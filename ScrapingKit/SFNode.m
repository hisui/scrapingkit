//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNode.h"
#import "SFNode+Local.h"

NSString *stringRepeatedAt(NSString *part, int count)
{
    NSMutableString *dest = NSMutableString.string;
    for (int i = 0; i < count; ++i) {
        [dest appendString:part];
    }
    return dest;
}

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

- (void)print:(int)indent
{
    [self doesNotRecognizeSelector:_cmd];
}

@end
