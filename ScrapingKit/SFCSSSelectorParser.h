//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSQuery+Local.h"
#import "SFRegExpScanner.h"

/**
 * This class parses a string representation of CSS selector query.
 */
@interface SFCSSSelectorParser : SFRegExpScanner

@property(nonatomic,readonly) SFSelectorChain *subject;

/**
 * Adds custom(user-level) filter.
 */
+ (void)addFilter:(NSString*)name
             with:(SFCSSFilter*(^)(SFCSSSelectorParser*))func;

/**
 * Initializes with a CSS selector query.
 */
- (id)initWithQuery:(NSString*)query;

/**
 * Parses the entire query to return a chain of compound selector.
 */
- (SFSelectorChain*)parse;
+ (SFSelectorChain*)parse:(NSString*)query;

/**
 * Proceeds parsing to get next compound selector.
 */
- (SFCSSFilter*)parseSelector;

/**
 * Throws an exception for reporing a syntax error. (never return)
 */
- (void)raiseError:(NSString*)message;

@end
