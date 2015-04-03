//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNode.h"

#ifdef __cplusplus
extern "C" {
#endif
    extern NSString *SFTextEncode(NSString *src);
    extern NSString *SFTextDecode(NSString *src);
#ifdef __cplusplus
}
#endif

/**
 * Text node.
 */
@interface SFText : SFNode
- (instancetype)initWithText:(NSString*)text;

@property(nonatomic,readonly) BOOL isBlank;
@end
