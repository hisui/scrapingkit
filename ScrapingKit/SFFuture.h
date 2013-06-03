//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFError.h"

@class SFFuture;
typedef SFFuture*(^SFFutureBlock)(id);

/**
 * This class represents an asynchronous process which returns a result or an error only once.
 */
@interface SFFuture : NSObject

@property(nonatomic,readonly) BOOL done;

+ (SFFuture*)fail:(id)result;
+ (SFFuture*)exit:(id)result;
+ (SFFuture*)timeout:(NSTimeInterval)interval;

+ (SFFuture*)untilExit:(SFFutureBlock*)make limit:(int)n;
+ (SFFuture*)untilFail:(SFFutureBlock*)make limit:(int)n;

- (void)wait:(void(^)(id,SFError*))func;

- (SFFuture*)willFail;
- (SFFuture*)willExit;

- (SFFuture*)map:(id(^)(id))func;
- (SFFuture*)aid:(id(^)(id))func;

- (SFFuture*)conj:(SFFutureBlock)next;
- (SFFuture*)disj:(SFFutureBlock)next;

- (SFFuture*)race:(SFFuture*)that;

- (SFFuture*)cons:(SFFuture*)that by:(id(^)(id,id))func;
- (SFFuture*)cons:(SFFuture*)that;

@end


/** 
 * Implementation helper for SFFuture.
 */
@interface SFFutureTemplate : SFFuture

/**
 * You must implement this method for aborting(cancel) a processing task.
 */
- (BOOL)queryCancel;

/**
 * Finishes this task and dispatches a success result.
 */
- (void)notifyExit:(id)result;

/**
 * Finishes this task and dispatches a failure result.
 */
- (void)notifyFail:(SFError*)error;

@end


/**
 * {SFFuture}の終了を通知を行います。
 */
@interface SFPromise : NSObject

@property SFFuture *future;

+ (SFPromise*)promise;
+ (SFPromise*)promise:(void(^)())cancel;

- (void)exit:(id)result;
- (void)fail:(id)error;

@end
