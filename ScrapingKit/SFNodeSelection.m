//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNodeSelection+Local.h"
#import "SFCSSQuery.h"

@implementation SFNodeSelection

- (SFNodeSelection*)flatMap:(NSArray*(^)(SFElement*))func
{
    NSMutableOrderedSet *set = NSMutableOrderedSet.orderedSet;
    for (SFElement *e in self.elements) {
        [set addObjectsFromArray:func(e)];
    }
    return [[SFArrayNodeSelection alloc] initWithElements:set.array];
}

- (SFNodeSelection*)map:(SFElement*(^)(SFElement*))func
{
    return [self flatMap:^NSArray*(SFElement *e) { return @[func(e)]; }];
}

- (SFNodeSelection*)append:(NSString*)query
{
    return
    [[SFQueryNodeSelection alloc] initWithElements:self.elements
                                      withSelector:query];
}

- (SFNodeSelection*)append:(NSString*)query
                    orElse:(NSArray*(^)(SFElement*))func
{
    return [self append:query];
}

@end


@implementation SFArrayNodeSelection
{
    NSArray *_elements;
}

@synthesize elements = _elements;

- (id)initWithElements:(NSArray*)elements
{
    if ((self = [self init])) {
        self->_elements = elements;
    }
    return self;
}

@end


@implementation SFQueryNodeSelection
{
    NSArray  *_elements;
    NSString *_query;
}

- (id)initWithElements:(NSArray*)elements
          withSelector:(NSString*)query
{
    if ((self = [self init])) {
        self->_elements = elements;
        self->_query    = query;
    }
    return self;
}

- (NSArray*)elements
{
    NSMutableOrderedSet *set = NSMutableOrderedSet.orderedSet;
    SFCSSQuery *query = [SFCSSQuery query:[@"*:base" stringByAppendingString:_query]];
    for (SFElement *e in _elements) {
        for (SFElement *e2 in [query findAll:e]) {
            [set addObject:e2];
        }
    }
    return set.array;
}

- (SFNodeSelection*)append:(NSString*)query
{
    return
    [[SFQueryNodeSelection alloc] initWithElements:_elements
                                      withSelector:[_query stringByAppendingString:query]];
}

@end
