//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFDocument+Local.h"
#import "SFElement.h"
#include <deque>
#include <vector>
#include <unordered_set>
#include "htmlparse.hpp"
#include "entities.hpp"
#include "tags.hpp"

typedef sf::basic_htmlparser<const char*> HTMLParser;

using std::get;

namespace std {
    template<> struct equal_to<NSString*>
    {
        bool operator()(NSString *lhs, NSString *rhs) const
        {
            return [lhs isEqual:rhs];
        }
    };
    
    template<> struct hash<NSString*>
    {
        size_t operator()(NSString *o) const
        {
            return size_t(o.hash);
        }
    };
}

/*
static std::unordered_set<NSString*> kVoidElements =
{
      @"area"
    , @"base"
    , @"br"
    , @"col"
    , @"embed"
    , @"hr"
    , @"img"
    , @"input"
    , @"keygen"
    , @"link"
    , @"meta"
    , @"param"
    , @"source"
    , @"track"
    , @"wbr"
};
*/

inline sf::Tag toTag(NSString *o) {
    return sf::ascii_to_Tag(o.UTF8String, o.length);
}

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
                                encoding:NSUTF32BigEndianStringEncoding];
}

static void closeElement(NSString *name, std::deque<SFElement*> &stack)
{
    for (int i = int(stack.size()) - 1; i >= 0; --i) {
        auto elem = stack[i];
        if ([elem.name isEqual:name]) {
            /*
            for (int j = i + 1; j < stack.size(); ++j) {
                auto e = stack[j];
                for (auto next = e.first; next; ) {
                    auto node = next;
                    next = next.next;
                    [elem insert:node before:nil];
                }
            }
            */
            stack.erase(stack.begin() + i, stack.end());
            break;
        }
    }
}

// http://www.w3.org/TR/html5/syntax.html#optional-tags
static void closeOptionalTags(NSString *name, std::deque<SFElement*> &stack)
{
    using namespace sf;
    if (stack.empty()) {
        return;
    }
    auto top = toTag(stack.back().name);
    switch (toTag(name)) {
        case TAG_li:
            if (top == TAG_li) goto close;
            break;
        case TAG_dd:
        case TAG_dt:
            if (top == TAG_dd ||
                top == TAG_dd) goto close;
            break;
        case TAG_optgroup:
            if (top == TAG_optgroup ||
                top == TAG_option) goto close;
            break;
        case TAG_option:
            if (top == TAG_option) goto close;
            break;
        case TAG_tbody:
        case TAG_tfoot:
            if (top == TAG_thead ||
                top == TAG_tbody ||
                top == TAG_tfoot) goto close;
        case TAG_tr:
            if (top == TAG_tr) goto close;
            break;
        case TAG_th:
        case TAG_td:
            if (top == TAG_th ||
                top == TAG_td) goto close;
            break;
            
        default:
            break;
    }
    return;
close:
    stack.pop_back();
}

static bool isVoidElement(NSString *name)
{
    using namespace sf;
    switch (toTag(name)) {
        case TAG_area:
        case TAG_base:
        case TAG_br:
        case TAG_col:
        case TAG_hr:
        case TAG_img:
        case TAG_input:
        case TAG_link:
        case TAG_meta:
        case TAG_param:
            return true;
        default:
            return false;
    }
}

static void parseHTML(SFElement *root, const char *pos, const char *end)
{
    std::deque<SFElement*> stack = { root };
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
                closeOptionalTags(node.name, stack);
                [stack.back() append:node];
                if (isVoidElement(node.name)) {
                    break;
                }
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
            closeElement(stringify(pair).lowercaseString, stack);
            break;
        }
    }
    /*
    for (int i = 1; i < stack.size(); ++i) {
        for (auto next = stack[i].first; next; ) {
            auto node = next;
            next = next.next;
            [root insert:node before:nil];
        }
    }
    */
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
