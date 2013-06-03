//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNode.h"
#import "SFNode+Local.h"

@implementation SFNode

// readonly property
- (SFNode*)next
{
    return _next && _next->_parent ? _next: nil;
}

- (NSString*)text
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (NSString*)dump
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (NSString*)stringify
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

@end
