//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFElement.h"

/**
 * This class represents a filter of CSS selector.
 */
@interface SFCSSFilter : NSObject
{
// 次のフィルター <(^_^;)
@public SFCSSFilter *next;
}

/**
 * Applies this filter to an element.
 */
- (BOOL)match:(SFElement*)element
      context:(SFElement*)context;

// for debug
@property(nonatomic,readonly) NSString *dump;

@end

/**
 * Template implementation for easy extension of user-level filter.
 * e.g.: "E:unko"
 */
@interface SFUserFilter : SFCSSFilter
@end


// E, *
@interface SFTypeSelector : SFCSSFilter
- (instancetype)initWithName:(NSString*)name;
@end

enum MatchType
{
    MATCH_EQUAL       =  0 ,
    MATCH_EQUAL_PART  = '~',
    MATCH_PREFIX      = '^',
    MATCH_SUFFIX      = '$',
    MATCH_SUBSTR      = '*',
};

// E[name], E[name=data], ...
@interface SFAttributeFilter : SFCSSFilter
- (instancetype)initWithName:(NSString*)name
                    withData:(NSString*)data
                    withKind:(enum MatchType)kind;
@end

enum EquationKind
{
    NTH_NONE,
    NTH_CHILD,
    NTH_CHILD_REV,
    NTH_OF_TYPE,
    NTH_OF_TYPE_REV,
};

// E:nth-*(Xn+Y)
@interface SFNEquation : SFCSSFilter
- (instancetype)initWithScale:(int)scale withBase:(int)base;
@end

// E:nth-[last-]child, nth-[last-]type-of
@interface SFNEquationFilter : SFCSSFilter
- (instancetype)initWithKind:(enum EquationKind)kind withEquation:(SFNEquation*)eq;
@end

// E:not(...)
@interface SFNotFilter : SFCSSFilter
- (instancetype)initWithFilter:(SFCSSFilter*)filter;
@end

// E:matches(a, b, c, ..)
@interface SFMatchesAnyFilter : SFCSSFilter
- (instancetype)initWithFilters:(NSArray*)filters;
@end

// E:only-child
@interface SFOnlyChildFilter : SFUserFilter
@end

// E:only-of-type
@interface SFOnlyOfTypeFilter : SFUserFilter
@end

// E:base
@interface SFBaseFilter : SFUserFilter
@end

// E:root
@interface SFRootFilter : SFUserFilter
@end

// E:empty
@interface SFEmptyFilter : SFUserFilter
@end

// E:blank
@interface SFBlankFilter : SFUserFilter
@end

// E:nth-match(Xn+Y of ...)
@interface SFNthMatchFilter : SFCSSFilter
- (instancetype)initWithLast:(BOOL)b
                    equation:(SFNEquation*)eq
                    selector:(SFCSSFilter*)filter;
@end

