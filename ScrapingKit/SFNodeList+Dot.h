//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNodeList.h"

@interface SFNodeList (Dot)

- (SFNodeList*(^)( NSString* )) find;

- (SFNodeList*(^)( SFElement*(^)(SFElement*) )) map;

- (SFNodeList*(^)( BOOL(^)(SFElement*) )) filter;

- (void(^)( void(^)(SFElement*) )) forEach;

@end
