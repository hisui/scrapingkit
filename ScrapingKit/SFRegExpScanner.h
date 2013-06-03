//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import <Foundation/Foundation.h>

/**
 * 
 */
@interface SFRegExpScanner : NSObject

/**
 * Sets/Gets a subject string.
 */
@property(nonatomic) NSString *source;

/**
 * Sets/Gets an offset of the subject.
 */
@property(nonatomic) NSInteger cursor;

/**
 * A character currently referred by current offset.
 */
@property(readonly,atomic) unichar code;

/**
 * Number of remaining characters.
 */
@property(readonly,atomic) NSInteger remaining;

/**
 * Initializes with a subject string.
 */
- (id)initWithData:(NSString*)data;

/**
 * Matches a regexp to remaining string to advance the cursor.
 */
- (NSTextCheckingResult*)scan:(NSRegularExpression*)pattern;

/**
 * Gets Nth-captured string at last scan. (1-origin)
 */
- (NSString*)$:(int)n;

/**
 * Gets a range of Nth-captured substring in matched string entire at last scan.
 */
- (NSRange)rangeAtIndex:(int)n;

@end
