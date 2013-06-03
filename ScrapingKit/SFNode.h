//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import <Foundation/Foundation.h>

// defined in SFElement.h
@class SFElement;

/**
 * This class represents a node in HTML document.
 */
@interface SFNode : NSObject

/**
 * Parent element.
 */
@property(nonatomic,readonly) SFElement *parent;

/**
 * Sibling node.
 */
@property(nonatomic,readonly) SFNode *next;
@property(nonatomic,readonly) SFNode *prev;

/**
 *
 */
@property(nonatomic,readonly) NSString *text;

// abstract
- (NSString*)dump;

/**
 * Gets text data in XML document which this node represents.
 */
- (NSString*)stringify;

@end
