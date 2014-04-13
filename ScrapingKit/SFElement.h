//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFNode.h"

/**
 * This class represents a tag in HTML document.
 */
@interface SFElement : SFNode

/**
 * Name of tag.
 */
@property(nonatomic) NSString *name;

/**
 * Text data this tag contains.
 */
@property(nonatomic) NSString *text;

/**
 * Returns attributes to this tag as an associative array.
 */
@property(nonatomic,readonly) NSDictionary *attributes;

/**
 * Number of child nodes.
 */
@property(nonatomic,readonly) size_t size;

@property(nonatomic,readonly) SFElement *prevElement;
@property(nonatomic,readonly) SFElement *nextElement;

/**
 * 
 */
@property(nonatomic,readonly) int nodeIndex;
@property(nonatomic,readonly) int lastNodeIndex;

/**
 *
 */
@property(nonatomic,readonly) int typeIndex;
@property(nonatomic,readonly) int lastTypeIndex;

/**
 * First child node.
 */
@property(nonatomic,readonly) SFNode    *first;
@property(nonatomic,readonly) SFElement *firstElement;

/**
 * 
 */
@property(nonatomic,readonly) NSArray *descendant;

/**
 * Initializes with a tag name and attributes.
 */
- (instancetype)initWithName:(NSString*)name;
- (instancetype)initWithName:(NSString*)name attrs:(NSDictionary*)attributes;

/**
 * Appends a child node.
 */
- (void)append:(SFNode*)node;

/**
 * Inserts a child node previous to the other one.
 */
- (void)insert:(SFNode*)node
        before:(SFNode*)dest;

/**
 * Removes a child node.
 */
- (BOOL)remove:(SFNode*)node;

/**
 * Finds whether or not a node is immediate child node of this element.
 */
- (BOOL)contains:(SFNode*)node;

/**
 * Gets attribute value of given key.
 */
- (NSString*)get:(NSString*)key;

/**
 * Sets attribute value of give key.
 */
- (void)set:(NSString*)value
     forKey:(NSString*)key;

/**
 *
 */
- (SFElement*)find:(NSString*)query;

/**
 *
 */
- (id <NSFastEnumeration>)filter:(NSString*)query;

@end
