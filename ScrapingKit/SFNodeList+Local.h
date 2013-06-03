//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNodeList.h"
#import "SFNodeSelection+Local.h"

@interface SFSynchronizedNodeList : SFNodeList
- (id)initWithSelection:(SFNodeSelection*)selection;
@end
