//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFElement.h"

/**
 * This class represents an executable (compiled) CSS selector.
 */
@interface SFCSSQuery : NSObject

/**
 * Creates new selector from a query.
 */
+ (SFCSSQuery*)query:(NSString*)query;

/**
 * Applies this selector to a context node and returns an element matched first.
 */
- (SFElement*)find1st:(SFElement*)context;

/**
 * Applies this selector to a context node and returns matched elements.
 */
- (id <NSFastEnumeration>)findAll:(SFElement*)context;

@end
