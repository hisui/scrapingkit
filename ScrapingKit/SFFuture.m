//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFFuture+Local.h"

@implementation SFFuture
{
	NSString *_name;
}

+ (SFFuture*)exit:(id)result
{
	return [[SFFutureDone alloc] initWithResult:result
                                      withError:nil];
}

+ (SFFuture*)fail:(SFError*)error
{
	return [[SFFutureDone alloc] initWithResult:nil
                                      withError:error];
}

// readonly property
- (BOOL)done
{
	[self doesNotRecognizeSelector:_cmd];
	return NO;
}

- (id)init
{
	if((self = [super init])) {
	}
	return self;
}

- (void)wait:(void(^)(id,SFError*))callback
{
	[self doesNotRecognizeSelector:_cmd];
}

- (void)cancel
{
	[self doesNotRecognizeSelector:_cmd];
}

- (SFFuture*)map:(id (^)(id))func
{
    return [[SFFutureMap alloc] initWithBase:self withFunc:func withFail:NO];
}

- (SFFuture*)aid:(id(^)(id))func
{
    return [[SFFutureMap alloc] initWithBase:self withFunc:func withFail:YES];
}

- (SFFuture*)conj:(SFFuture*(^)(id))next
{
	return [[SFFutureConj alloc] initWithBase:self withNext:next];
}

- (SFFuture*)disj:(SFFuture*(^)(id))next
{
	return [[SFFutureDisj alloc] initWithBase:self withNext:next];
}

@end


@implementation SFFutureTemplate

{
	int _dispatch;
	void (^_callback)(id,SFError*);
	BOOL _canceled;
	BOOL _wait;
	BOOL _done;
}

- (id)init
{
	if((self = [super init])) {
	}
	return self;
}

- (void)dealloc
{
}

- (void)wait:(void(^)(id,SFError*))callback
{
	if(_dispatch != -1) {
        if(_callback) {
            [NSException raise:NSInvalidArgumentException
                        format:@"callback fuction has already been set."];
        }
        _callback = [callback copy];
    }
}

- (void)cancel
{
	// すでに通知済みの場合はキャンセル出来ない(というか、意味ない)
	if(_dispatch == -1) {
        return;
    }
	if(!(_canceled || _wait)) {
		if([self queryCancel]) {
			// キャンセルは、他の通知より優先される
			[self notifyFail:[SFError errorAsCancel:nil]];
			return;
		}
		// キャンセルを保留する場合
		_wait = YES;
	}
}

- (BOOL)queryCancel
{
	[self doesNotRecognizeSelector:_cmd];
	return NO;
}

- (void)notifyExit:(id)result
{
	if(_done) {
		[NSException raise:NSInvalidArgumentException
                    format:@"This task(%@) has been done..", @"todo"];
	}
	_done = YES;
	[self dispatch:result error:nil];
}

- (void)notifyFail:(SFError*)error
{
	// 初めのキャンセルは{_done}を無視する
	if(!_canceled && error.cancel) {
		_canceled = YES;
	}
	else if(_done) {
		[NSException raise:NSInvalidArgumentException
                    format:@"This task(%@) has been done..", @"todo"];
	}
	_done = YES;
	[self dispatch:nil error:error];
}

- (void)dispatch:(id)result error:(SFError*)error
{
	NSAssert(_dispatch != -1, @"_dispatch == -1");
	int count = ++_dispatch;
	dispatch_async(dispatch_get_main_queue(), ^
    {
        if (_dispatch == count) { // 他のキャンセルに打ち消されてないか
            _dispatch = -1;
            _callback(result, error);
            _callback = nil;
        }
    });
}

@end


@implementation SFPromisedFuture
{
    void (^_cancel_impl)();
}

- (id)initWithBlock:(void(^)())block
{
    if((self = [self init])) {
        self->_cancel_impl = [block copy];
    }
    return self;
}

#pragma mark SFFutureTemplate
- (BOOL)queryCancel
{
    _cancel_impl();
	return YES;
}

@end


@implementation SFPromise
{
    SFPromisedFuture *_future;
}

- (id)initWithBlock:(void(^)())block
{
    if((self = [self init])) {
        self->_future = [[SFPromisedFuture alloc] initWithBlock:block];
    }
    return self;
}

+ (SFPromise*)promise
{
    return [[self alloc] initWithBlock:^{}];
}

+ (SFPromise*)promise:(void(^)())cancel
{
    return [[self alloc] initWithBlock:cancel];
}

- (void)exit:(id)     result { [_future notifyExit:result]; }
- (void)fail:(SFError*)error { [_future notifyFail:error ]; }

@end


@implementation SFFutureDone
{
	id _result;
	SFError *_error;
}

- (BOOL)done
{
	return true;
}

- (id)initWithResult:(id)result withError:(SFError*)error
{
	if((self = [self init])) {
		self->_result = result;
		self->_error  = error;
	}
	return self;
}

- (void)wait:(void(^)(id,SFError*))callback
{
    dispatch_async(dispatch_get_main_queue(), ^{
        callback(_result, _error);
    });
}

- (void)cancel
{
}

@end


@implementation SFFutureTime
{
	id _result;
}

- (id)initWithResult:(id)result after:(double)sec
{
	if((self = [self init])) {
		self->_result = result;
		dispatch_after
         ( dispatch_time(DISPATCH_TIME_NOW, sec * NSEC_PER_SEC)
         , dispatch_get_main_queue(), ^
        {
            if(!self.done) [self notifyExit:_result];
        });
	}
	return self;
}

- (BOOL)queryCancel
{
	_result = nil;
	return YES;
}

@end


@implementation SFFutureMap
{
	SFFuture *_base;
	id (^_func)(id);
	BOOL _fail;
}

- (BOOL)done
{
	return _base.done;
}

- (id)initWithBase:(SFFuture*)base
		  withFunc:(id(^)(id))func
		  withFail:(BOOL)fail
{
	if((self = [self init])) {
		self->_base = base;
		self->_fail = fail;
		self->_func = [func copy];
	}
	return self;
}

- (void)wait:(void(^)(id,SFError*))callback
{
	[_base wait:^(id o, SFError *e)
    {
        id tmp;
		if(_fail) {
			if(o) { callback(o, nil); return; }
			tmp = e;
		}
		else {
			if(e) { callback(nil, e); return; }
			tmp = o;
		}
		[tmp = _func(tmp) isMemberOfClass:[SFError class]]
        ? callback(nil, tmp)
        : callback(tmp, nil);
	}];
}

- (void)cancel { [_base cancel]; }

@end


@implementation SFFutureNext
{
@protected
	SFFuture *_base;
	SFFuture *(^_next)(id);
}

- (id)initWithBase:(SFFuture*)base
		  withNext:(SFFuture*(^)(id))next
{
	if((self = [self init])) {
		self->_base = base;
		self->_next = [next copy];
		[base wait:^(id o, SFError *e)
        {
            SFFuture *(^next)(id) = _next;
            _base = nil;
            _next = nil;
            if([self select:&o with:o error:e]) {
                [_base = next(o) wait:^(id o, SFError *e)
                {
                    _base = nil;
                    if(e) [self notifyFail:e];
                    else  [self notifyExit:o];
                }];
            }
        }];
	}
	return self;
}

- (BOOL)queryCancel
{
	[_base cancel];
	return NO;
}

- (BOOL)select:(id __strong*)dest
          with:(id)o error:(SFError*)e
{
    return NO;
}

@end


@implementation SFFutureConj

- (BOOL)select:(id __strong*)dest
          with:(id)o error:(SFError*)e
{
    if(e != nil) {
        [self notifyFail:e];
        return NO;
    }
    *dest = o;
    return YES;
}

@end


@implementation SFFutureDisj

- (BOOL)select:(id __strong*)dest
          with:(id)o error:(SFError*)e
{
    if(e == nil) {
        [self notifyExit:o];
        return NO;
    }
    *dest = e;
    return YES;
}

@end


