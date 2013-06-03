//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import <Foundation/Foundation.h>

@interface SFError : NSObject

+ (SFError*)errorWithInfo:(id)info;
+ (SFError*)errorWithInfo:(id)info withBase:(SFError*)base;
+ (SFError*)errorAsCancel:(id)info;

- (NSString*)description;

@property(nonatomic,readonly)   id info;
@property(nonatomic,readonly) BOOL cancel;

@end
