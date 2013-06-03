//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSQuery.h"
#import "SFNodeList.h"
#import "SFCSSFilter.h"

// Kind of combinators.
enum Combinator
{
    COMB_CHILDREN   = '>',
    COMB_SIBLING1   = '+',
    COMB_SIBLINGS   = '~',
    COMB_DESCENDANT = ' ',
    COMB_IDREF      = '/',
};

// This class represents a compound selector.
@interface SFSelectorChain : NSObject
{
@public
    SFSelectorChain *tail;
    SFCSSFilter *filter;
    enum Combinator combinator;
    NSString *idref; // <(^_^;)
}
- (id)initWithTail:(SFSelectorChain*)chain;
@end

@interface SFQueryResult : SFNodeList
- (id)initWithEnumerator:(id <NSFastEnumeration>)enumerator;
@end
