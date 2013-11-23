//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFWebClient.h"

@implementation SFWebClientResponse
{
    NSInteger _code;
	NSData   *_body;
}

- (id)initWithCode:(NSInteger)code
		  withBody:(NSData*)body
{
	if ((self = [self init])) {
		self->_code = code;
		self->_body = body;
	}
	return self;
}

- (NSString*)utf8
{
	return [[NSString alloc] initWithData:_body
								 encoding:NSUTF8StringEncoding];
}

@end


@interface SFWebRequestTask : SFFutureTemplate <NSURLConnectionDelegate>
- (id)initWithRequest:(NSURLRequest*)request;
@end

@implementation SFWebRequestTask
{
	NSURLConnection   *_conn;
	NSMutableData     *_buf;
	NSHTTPURLResponse *_res;
}

- (id)initWithRequest:(NSURLRequest*)request
{
	if((self = [self init])) {
		self->_buf = [NSMutableData data];
		self->_res = nil;
		// リクエストを送信(キャンセル用に保持する必要あり)
		self->_conn =
		[[NSURLConnection alloc] initWithRequest:request
										delegate:self
								startImmediately:YES];
        NSLog(@"SFHttpRequestTask#init url=%@", request.URL);
	}
	return self;
}

- (void)connection:(NSURLConnection*)conn
	didReceiveData:(NSData*)data
{
	[_buf appendData:data];
}

- (void)connection:(NSURLConnection*)conn
didReceiveResponse:(NSURLResponse*)response
{
	_res = (NSHTTPURLResponse*) response;
}

- (void)connection:(NSURLConnection*)conn
  didFailWithError:(NSError*)error
{
	[self notifyFail:[SFError errorWithInfo:error]];
}

- (void)connectionDidFinishLoading:(NSURLConnection*)conn
{
	[self notifyExit:
	 [[SFWebClientResponse alloc] initWithCode:_res.statusCode
                                      withBody:_buf]];
}

- (BOOL)queryCancel
{
	[_conn cancel];
	return YES;
}

@end


@implementation SFWebClient
{
	NSMutableDictionary *_defaultHeaders;
}

- (void)appendHeaders:(NSDictionary*)headers
				   to:(NSMutableURLRequest*)request
{
	for(NSString *name in headers) {
		[request setValue:[headers objectForKey:name]
	   forHTTPHeaderField:name];
	}
}

- (void)set:(NSString*)value
  forHeader:(NSString*)name;
{
	[_defaultHeaders setObject:value forKey:name];
}

- (SFFuture*)get:(NSURL*)url
{
	return [self get:url withHeaders:NSDictionary.dictionary];
}

- (SFFuture*)get:(NSURL*)url
     withHeaders:(NSDictionary*)headers
{
	NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL: url];
	[self appendHeaders:_defaultHeaders to:request];
	[self appendHeaders:headers         to:request];
	return [[SFWebRequestTask alloc] initWithRequest:request];
}

- (SFFuture*)post:(NSData*)data to:(NSURL*)url
{
	return [self post:data to:url withHeaders:NSDictionary.dictionary];
}

- (SFFuture*)post:(NSData*)data to:(NSURL*)url
      withHeaders:(NSDictionary*)headers
{
	NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
	request.HTTPMethod = @"POST";
	request.HTTPBody   = data;
	[self appendHeaders:_defaultHeaders to:request];
	[self appendHeaders:headers         to:request];
	return [[SFWebRequestTask alloc] initWithRequest:request];
}

@end
