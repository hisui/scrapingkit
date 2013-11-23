//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFFuture.h"

@interface SFFuture (Local)
@end


@interface SFFutureDone : SFFuture
- (id)initWithResult:(id)result withError:(SFError*)error;
@end

@interface SFFutureTime : SFFutureTemplate @end

@interface SFFutureNext : SFFutureTemplate
- (id)initWithBase:(SFFuture*)base withNext:(SFFuture*(^)(id))next;
@end

@interface SFFutureConj : SFFutureNext @end
@interface SFFutureDisj : SFFutureNext @end

@interface SFFutureMap : SFFuture
- (id)initWithBase:(SFFuture*)base
		  withFunc:(id(^)(id))func
		  withFail:(BOOL)fail;
@end


@interface SFPromisedFuture : SFFutureTemplate
@end
