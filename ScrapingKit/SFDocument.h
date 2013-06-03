//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFElement.h"
#import "SFText.h"

/**
 * This class represents an entire HTML document.
 */
@interface SFDocument : SFElement

/**
 * Initializes with result of parse of given HTML document.
 */
+ (SFDocument*)documentWithHTML:(NSString*)html;

/**
 * Gets an element with an id.
 */
- (SFElement*)getElementById:(NSString*)ID;

@end

