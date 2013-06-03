//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNode.h"

extern NSString *SFTextEncode(NSString *src);
extern NSString *SFTextDecode(NSString *src);

/**
 * Text node.
 */
@interface SFText : SFNode
- (id)initWithText:(NSString*)text;

@property(nonatomic,readonly) BOOL isBlank;
@end
