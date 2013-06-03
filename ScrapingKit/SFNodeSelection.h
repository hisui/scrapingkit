//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFElement.h"

/**
 * (for internal use) This class represents a certain HTML elements.
 */
@interface SFNodeSelection : NSObject

/**
 * The elements.
 */
@property(nonatomic,readonly) NSArray *elements;

/**
 * @see SFNodeList#map
 */
- (SFNodeSelection*)map:(SFElement*(^)(SFElement*))func;

/**
 * @see SFNodeList#flatMap
 */
- (SFNodeSelection*)flatMap:(NSArray*(^)(SFElement*))func;

/**
 * <(^_^;)
 */
- (SFNodeSelection*)append:(NSString*)query;
- (SFNodeSelection*)append:(NSString*)query
                    orElse:(NSArray*(^)(SFElement*))func;

@end
