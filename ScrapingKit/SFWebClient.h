//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFFuture.h"

/**
 * SFHttpClient-get/post の実行結果を表します。
 */
@interface SFWebClientResponse : NSObject

/**
 * HTTPステータスコードです。
 */
@property(nonatomic,readonly) int code;

/**
 * レスポンスボディです。
 */
@property(nonatomic,readonly) NSData   *body;
@property(nonatomic,readonly) NSString *utf8;

@end


/**
 * HTTP接続を行います。
 */
@interface SFWebClient : NSObject

/**
 * リクエストヘッダーのデフォルト値を設定します。
 */
- (void)set:(NSString*)value forHeader:(NSString*)name;

/**
 * GETリクエストを送信し、レスポンスを取得します。
 */
- (SFFuture*)get:(NSURL*)url;
- (SFFuture*)get:(NSURL*)url
     withHeaders:(NSDictionary*)headers;

/**
 * POSTリクエストを送信し、レスポンスを取得します。
 */
- (SFFuture*)post:(NSData*)data to:(NSURL*)url;
- (SFFuture*)post:(NSData*)data to:(NSURL*)url
      withHeaders:(NSDictionary*)headers;

@end
