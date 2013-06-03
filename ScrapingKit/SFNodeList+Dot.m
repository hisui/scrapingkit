//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNodeList+Dot.h"

@implementation SFNodeList (Dot)

- (SFNodeList*(^)( NSString* )) find
{
    return ^SFNodeList*(NSString *a) { return [self find:a]; };
}

- (SFNodeList*(^)( SFElement*(^)(SFElement*) )) map
{
    return ^SFNodeList*(SFElement*(^f)(SFElement*)) { return [self map:f]; };
}

- (SFNodeList*(^)( BOOL(^)(SFElement*) )) filter
{
    return ^SFNodeList*(BOOL(^f)(SFElement*)) { return [self filter:f]; };
}

- (void(^)( void(^)(SFElement*) )) forEach
{
    return ^void(void(^f)(SFElement*)) { [self forEach:f]; };
}

@end
