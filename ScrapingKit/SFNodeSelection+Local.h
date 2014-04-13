//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNodeSelection.h"

@interface SFArrayNodeSelection : SFNodeSelection
- (instancetype)initWithElements:(NSArray*)elements;
@end

@interface SFQueryNodeSelection : SFNodeSelection
- (instancetype)initWithElements:(NSArray*)elements
                    withSelector:(NSString*)query;
@end
