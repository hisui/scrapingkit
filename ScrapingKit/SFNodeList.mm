//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNodeList+Local.h"
#import "SFDocument.h"

static NSArray *vectorize(SFElement *elem)
{
    NSMutableArray *a = NSMutableArray.array;
    for (; elem; elem = elem.nextElement) {
        [a addObject:elem];
    }
    return a;
}

@implementation SFNodeList

+ (SFNodeList*)nodeListWithElement:(SFElement*)element
{
    return [SFSynchronizedNodeList nodeListWithElements:@[element]];
}

+ (SFNodeList*)nodeListWithElements:(NSArray*)elements
{
    return [SFSynchronizedNodeList nodeListWithElements:elements];
}

+ (SFNodeList*)nodeListWithHTML:(NSString*)html
{
    return [self nodeListWithElement:[SFDocument documentWithHTML:html]];
}

- (SFNodeList*)bind:(SFNodeSelection*(^)(SFNodeSelection*))func
{
	[self doesNotRecognizeSelector:_cmd]; // abstract
    return nil;
}

- (SFNodeList*)find:(NSString*)query by:(char)c
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *o) {
        return [o append:[NSString stringWithFormat:@"%c%@", c, query]];
    }];
}

- (SFNodeList*)find:(NSString*)query
{
    return [self find:query by:' '];
}

- (SFNodeList*)children:(NSString*)query
{
    return [self find:query by:'>'];
}

- (SFNodeList*)siblings:(NSString*)query
{
    return [self find:query by:'~'];
}

- (SFNodeList*)flatMap:(SFNodeList*(^)(SFElement*))func
{
    // TODO
    return nil;
}

- (SFNodeList*)map:(SFElement*(^)(SFElement*))func
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *o) {
        return [o map:^SFElement*(SFElement *e) { return func(e); }];
    }];
}

- (SFNodeList*)filter:(BOOL(^)(SFElement*))func
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *o) {
        return [o flatMap:^NSArray*(SFElement *e) {
            return func(e) ? @[e]: @[];
        }];
    }];
}

- (void)forEach:(void(^)(SFElement*))func
{
    [self bind:^SFNodeSelection*(SFNodeSelection *o) {
        return [o flatMap:^NSArray*(SFElement *e) {
            func(e);
            return @[];
        }];
    }];
}

- (SFNodeList*)descendants
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *e) {
        return [e append:@" *" orElse:^NSArray*(SFElement *e) {
            return e.descendant;
        }];
    }];
}

- (SFNodeList*)children
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *e) {
        return [e append:@">*" orElse:^NSArray*(SFElement *e) {
            return vectorize(e.firstElement);
        }];
    }];
}

- (SFNodeList*)siblings
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *e) {
        return [e append:@"~*" orElse:^NSArray*(SFElement *e) {
            return vectorize(e.nextElement);
        }];
    }];
}

- (SFNodeList*)prev
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *e) {
        return [e flatMap:^NSArray*(SFElement *e) {
            return (e = e.prevElement) ? @[e]: @[];
        }];
    }];
}

- (SFNodeList*)next
{
    return [self bind:^SFNodeSelection*(SFNodeSelection *e) {
        return [e append:@"+*" orElse:^NSArray*(SFElement *e) {
            return (e = e.nextElement) ? @[e]: @[];
        }];
    }];
}

@end


@implementation SFSynchronizedNodeList
{
    SFNodeSelection *_selection;
}

+ (SFNodeList*)nodeListWithElements:(NSArray*)elements
{
    return [[SFSynchronizedNodeList alloc] initWithSelection:
            [[SFArrayNodeSelection alloc] initWithElements:elements]];
}

- (id)initWithSelection:(SFNodeSelection *)selection
{
    if ((self = [self init])) {
        self->_selection = selection;
    }
    return self;
}

- (SFNodeList*)bind:(SFNodeSelection*(^)(SFNodeSelection*))func
{
    return [[SFSynchronizedNodeList alloc] initWithSelection:func(_selection)];
}

@end
