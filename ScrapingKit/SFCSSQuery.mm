//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSQuery+Local.h"
#import "SFNode+Local.h"
#import "SFCSSSelectorParser.h"

#include <unordered_map>
#include <deque>

namespace
{

// セレクターを適用して孫要素の集合を得る
class CssQueryProcessor
{
    enum Trib: uint64_t
    {
        TRI_UNDECIDED = 0,
        TRI_FAIL      = 1,
        TRI_SUCCESS   = 2,
    };
    
    struct Cursor
    {
        SFElement *next __unsafe_unretained;
        int index;
    };
    
    struct Choice
    {
        SFSelectorChain *head __unsafe_unretained;
        Cursor state;
        size_t level;
    };
public:
    CssQueryProcessor(SFSelectorChain *head, SFSelectorChain *subj, SFElement *context)
    :elements(context.descendant)
    ,refs(NSMutableDictionary.dictionary)
    ,head(head)
    ,subj(subj ? subj: head)
    ,context(context)
    ,i(0)
    {
        for (SFElement *e in elements) {
            dp.insert(std::make_pair(uintptr_t(e), 0));
        }
    }
    
    SFElement *next()
    {
        while (!choices.empty()) {
            auto e =
            choices.    back();
            choices.pop_back();
            __unsafe_unretained SFElement *dest = nil;
            if (choose(e.state, dest, e.head, e.level) == TRI_SUCCESS) {
                return dest;
            }
        }
        while(i != elements.count) {
            __unsafe_unretained SFElement *elem = elements[i++];
            __unsafe_unretained SFElement *dest = subj ? nil: elem;
            if (trace(elem, dest, head, 0) == TRI_SUCCESS) {
                return dest;
            }
        }
        return nil;
    }
    
    Trib choose(Cursor pos, __unsafe_unretained SFElement *&dest, SFSelectorChain *head, size_t level)
    {
        auto trib = TRI_FAIL;
        auto elem = pos.next;
        switch (head->combinator) {
        case COMB_DESCENDANT:
        case COMB_CHILDREN:
            while ((elem = elem.parent)
                    && (trib = trace(elem, dest, head->tail, level)) == TRI_FAIL
                    && head->combinator != COMB_CHILDREN
                    && elem != context);
                
            pos.next = elem == context ? nil: pos.next;
            break;
        case COMB_SIBLING1:
        case COMB_SIBLINGS:
            while ((elem = elem.prevElement)
                    && (trib = trace(elem, dest, head->tail, level)) == TRI_FAIL
                    && head->combinator != COMB_SIBLING1);
            
            pos.next = elem;
            break;
        case COMB_IDREF: // あるidを持つ要素はドキュメント中にひとつしかないと仮定する
            {
                NSMutableArray *a = refs[head->idref];
                if (!a) {
                    a = refs[head->idref] = [NSMutableArray array];
                    for (SFElement *e in elements) {
                        if ([e get:head->idref]) [a addObject:e];
                    }
                }
                auto Id = [elem get:@"id"];
                for (;;) {
                    if (pos.index >= a.count) {
                        pos.next = nil;
                        break;
                    }
                    if ([[elem = a[pos.index++] get:head->idref] isEqualToString:Id]
                        && (trib = trace(elem, dest, head->tail, level)) != TRI_FAIL) break;
                }
            }
            break;
        }
        // サブジェクトより右にいるケース(←いみふめい)
        if (!dest && trib == TRI_SUCCESS) {
            switch (head->combinator) {
            case COMB_DESCENDANT:
            case COMB_SIBLINGS:
            case COMB_IDREF:
                if (pos.next) {
                    choices.push_back({head, pos, level});
                }
            default:;
            }
            dpset(elem, level, TRI_FAIL); // これ重要
        }
        return trib;
    }
    
    Trib trace(__unsafe_unretained SFElement *const elem,
               __unsafe_unretained SFElement *&dest, SFSelectorChain *head, size_t level)
    {
        Trib last = dpget(elem, level);
        if (last != TRI_UNDECIDED) {
            return last;
        }
        for (auto cur = head->filter; cur; cur = cur->next) {
            if (![cur match:elem context:context]) {
                dpset(elem, level, TRI_FAIL);
                return TRI_FAIL;
            }
        }
        if (head == subj) { // !...
            dest = elem;
        }
        Trib trib = TRI_SUCCESS;
        if (head->tail) {
            trib = elem == context ? TRI_FAIL: choose({elem, 0}, dest, head, level+1);
        }
        dpset(elem, level, elem == dest ? TRI_FAIL: trib);
        return trib;
    }
    
    inline Trib dpget(__unsafe_unretained SFElement *e, size_t level)
    {
        return Trib((dp[uintptr_t(e)] >> level*2) & 3);
    }
    
    inline void dpset(__unsafe_unretained SFElement *e, size_t level, Trib result)
    {
        dp[uintptr_t(e)] |= (uint64_t(result) & 3) << level*2;
    }
    
private:
    NSArray             *const elements;
    NSMutableDictionary *const refs;
    __unsafe_unretained SFSelectorChain *const head;
    __unsafe_unretained SFSelectorChain *const subj;
    __unsafe_unretained SFElement *const context;
    size_t i;
    std::unordered_map<uintptr_t,uint64_t> dp;
    std::deque<Choice> choices;

};
}

@implementation SFSelectorChain
- (id)initWithTail:(SFSelectorChain*)chain
{
    if((self = [self init])) {
        self->tail = chain;
    }
    return self;
}

- (NSString*)description
{
    NSMutableString *buf = NSMutableString.string;
    if(tail) {
        [buf appendString:tail.description];
    }
    [buf appendFormat:@"%c", char(combinator)];
    for(auto cur = filter; cur; cur = cur->next) {
        [buf appendString:cur.dump];
    }
    return buf;
}
@end

@interface SFSelectorEnumeration : NSObject <NSFastEnumeration>
@end

@implementation SFSelectorEnumeration
{
    std::unique_ptr<CssQueryProcessor> _processor;
}
- (id)initWithContext:(SFElement*)context
             withHead:(SFSelectorChain*)head
             withSubj:(SFSelectorChain*)subj
{
    if ((self = [self init])) {
        self->_processor.reset(new CssQueryProcessor(head, subj, context));
    }
    return self;
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state
                                  objects:(__unsafe_unretained id*)stackbuf
                                    count:(NSUInteger)len
{
	int count = 0;
	if (state->state++ == 0) {
		state->mutationsPtr = &state->extra[0];
	}
    if (auto e = _processor->next()) {
        state->itemsPtr = stackbuf;
		while (e && count < len) {
			stackbuf[count++] = e, e = _processor->next();
		}
    }
	return count;
}
@end

@implementation SFCSSQuery
{
    SFSelectorChain *_head;
    SFSelectorChain *_subj;
}

+ (SFCSSQuery*)query:(NSString*)query
{
    return [[SFCSSQuery alloc] initWithQuery:query];
}

- (id)initWithQuery:(NSString*)query
{
    auto parser = [[SFCSSSelectorParser alloc] initWithQuery:query];
    if((self = [self init])) {
        self->_head = [parser parse];
        self->_subj = parser.subject;
    }
    return self;
}

- (SFElement*)find1st:(SFElement*)context
{
    return CssQueryProcessor(_head, _subj, context).next();
}

- (id <NSFastEnumeration>)findAll:(SFElement*)context
{
    return [[SFSelectorEnumeration alloc] initWithContext:context
                                                 withHead:_head
                                                 withSubj:_subj];
}
@end

@implementation SFQueryResult
{
    NSArray *_elements;
}

- (id)initWithEnumerator:(id <NSFastEnumeration>)enumerator
{
    if ((self = [self init])) {
        NSMutableArray *a = [NSMutableArray array];
        for (SFElement *e in enumerator) {
            [a addObject:e];
        }
        self->_elements = a;
    }
    return self;
}

@end
