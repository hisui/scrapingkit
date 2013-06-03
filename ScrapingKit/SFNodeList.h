//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFElement.h"

/**
 * A list of selected HTML element instances.
 */
@interface SFNodeList : NSObject

/**
 * New NodeList constituted of the given element.
 */
+ (SFNodeList*)nodeListWithElement:(SFElement*)element;

/**
 * New NodeList constituted of the given elements.
 */
+ (SFNodeList*)nodeListWithElements:(NSArray*)elements;

/**
 * New NodeList represents a HTML document.
 */
+ (SFNodeList*)nodeListWithHTML:(NSString*)html;

/**
 * New NodeList which represents a HTML document loaded from the given URL.
 */
//+ (SFNodeList*)open:(NSString*)url;

/**
 * Selects elements to which a query matches.
 */
- (SFNodeList*)find:(NSString*)query;

- (SFNodeList*)children:(NSString*)query;
- (SFNodeList*)siblings:(NSString*)query;

/**
 * Collects elements of result of function application to all the elements.
 */
- (SFNodeList*)flatMap:(SFNodeList*(^)(SFElement*))func;

/**
 * Collects elements of result of function application to all the elements.
 */
- (SFNodeList*)map:(SFElement*(^)(SFElement*))func;

/**
 * Selects elements which a predicate accepts.
 */
- (SFNodeList*)filter:(BOOL(^)(SFElement*))func;

/**
 * Applies a given function to all the elements each.
 */
- (void)forEach:(void(^)(SFElement*))func;

@property(nonatomic,readonly) SFNodeList *descendants;
@property(nonatomic,readonly) SFNodeList *children;
@property(nonatomic,readonly) SFNodeList *siblings;
@property(nonatomic,readonly) SFNodeList *next;
@property(nonatomic,readonly) SFNodeList *prev;

@end
