//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFDocument+Local.h"
#import "SFElement.h"
#include <deque>
#include <vector>
#include "htmlparse.hpp"
#include "entities.hpp"

typedef sf::basic_htmlparser<const char*> HTMLParser;

using std::get;

static NSString *stringify(const HTMLParser::pair_t &pair)
{
    std::vector<uint32_t> dest;
    auto pos = sf::make_unicode_iterator(get<0>(pair));
    auto end = sf::make_unicode_iterator(get<1>(pair));
    while (pos != end) {
        uint32_t c;
        auto last = pos;
        auto head = sf::htmlentity_decode_next(pos, end, c);
        if (head == end) {
            dest.insert(dest.end(), pos, end);
            break;
        }
        dest.insert(dest.end(), last, head);
        dest.push_back(c);
    }
    std::transform(dest.begin(), dest.end(), dest.begin(), CFSwapInt32HostToBig);
    return [NSString.alloc initWithBytes:&dest[0]
                                  length:dest.size() * 4
                                encoding:NSUTF32StringEncoding];
}

static void parseHTML(SFElement *root, const char *pos, const char *end)
{
    std::deque<SFElement*> stack;
    stack.push_back(root);
    HTMLParser::pair_t pair;
    HTMLParser parser(pos, end);
    while (auto type = parser.enter_elem(pair)) {
        switch (type) {
        default:
        case sf::ELEM_TEXT:
            [stack.back() append:[SFText.alloc initWithText:stringify(pair)]];
            break;
        case sf::ELEM_BEGIN:
            {
                auto map = NSMutableDictionary.dictionary;
                HTMLParser::pair_t key;
                HTMLParser::pair_t val;
                while (auto kind = parser.next_attr(key, val)) {
                    map[stringify(key).lowercaseString] = kind == sf::ATTR_KEY
                        ? stringify(key).lowercaseString
                        : stringify(val);
                }
                auto node = [SFElement.alloc initWithName:stringify(pair).lowercaseString attrs:map];
                [stack.back() append:node];
                switch (parser.leave_elem()) {
                case sf::ELEM_ERROR:
                case sf::ELEM_CLOSE:
                    break;
                default:
                    stack.push_back(node);
                }
            }
            break;
        case sf::ELEM_CLOSE:
            {
                auto name = stringify(pair).lowercaseString;
                for (int i = int(stack.size()) - 1; i >= 0; --i) {
                    auto elem = stack[i];
                    if ([elem.name isEqualToString:name]) {
                        for (int j = i + 1; j < stack.size(); ++j) {
                            auto e = stack[j];
                            for (auto next = e.first; next; ) {
                                 auto node = next;
                                next = next.next;
                                [elem insert:node before:nil];
                            }
                        }
                        stack.erase(stack.begin() + i, stack.end());
                        break;
                    }
                }
            }
            break;
        }
    }
    for (int i = 1; i < stack.size(); ++i) {
        for (auto next = stack[i].first; next; ) {
            auto node = next;
            next = next.next;
            [root insert:node before:nil];
        }
    }
}

@implementation SFDocument

+ (SFDocument*)documentWithHTML:(NSString*)html
{
    auto doc = [SFDocument.alloc initWithName:@"document"];
    auto src = html.UTF8String;
    parseHTML(doc, src, src + [html lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    return doc;
}
    
- (instancetype)initWithRoot:(SFElement*)root
{
    if ((self = [self initWithName:@"<>"])) {
        [self append:root];
    }
    return self;
}

- (SFElement*)getElementById:(NSString*)ID
{
    for (SFElement *e in self.descendant) { // <(^_^;)
        if ([[e get:@"id"] isEqualToString:ID]) return e;
    }
    return nil;
}

@end
