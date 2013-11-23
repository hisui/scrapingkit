//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFDocument+Local.h"
#import "SFElement.h"

#include <deque>
#include "htmlparse.hpp"

typedef sf::basic_htmlparser<const char*> HTMLParser;

static NSString *stringify(const HTMLParser::pair_t &pair)
{
    // FIXME ここ、何故かnilになることがある・・・
    auto tmp =
    [[NSString alloc] initWithBytes:pair.first
                             length:pair.second - pair.first
                           encoding:NSUTF8StringEncoding];
    return tmp ? tmp: @"";
}

static void parseHTML(SFElement *root, const char *pos, const char *end)
{
    std::deque<SFElement* __strong> stack;
    stack.push_back(root);
    HTMLParser::pair_t pair;
    HTMLParser parser(pos, end);
    while (auto type = parser.enter_elem(pair)) {
        switch (type) {
        default:
        case sf::ELEM_TEXT:
            [stack.back() append:
             [[SFText alloc] initWithText:stringify(pair)]];
            break;
        case sf::ELEM_BEGIN:
            {
                NSMutableDictionary *map = NSMutableDictionary.dictionary;
                HTMLParser::pair_t key;
                HTMLParser::pair_t val;
                while (auto kind = parser.next_attr(key, val)) {
                    map[stringify(key)] = kind == sf::ATTR_KEY
                        ? stringify(key).lowercaseString
                        : stringify(val);
                }
                auto node = [[SFElement alloc]
                             initWithName:stringify(pair).lowercaseString withAttr:map];
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
                                [elem insert:node before:nil]; // おっそそ〜。。。
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
}

@implementation SFDocument

+ (SFDocument*)documentWithHTML:(NSString*)html
{
    auto doc = [[SFDocument alloc] initWithName:@"document"];
    auto src = html.UTF8String;
    parseHTML(doc, src, src + [html lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    return doc;
}
    
- (id)initWithRoot:(SFElement*)root
{
    if ((self = [self initWithName:@"<>"])) {
        [self append:root];
    }
    return self;
}

- (SFElement*)getElementById:(NSString*)ID
{
    for (SFElement *e in self.descendant) { // <(^_^;)
        if ([[e get:@"id"] isEqualToString:ID]) {
            return e;
        }
    }
    return nil;
}

@end
