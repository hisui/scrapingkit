//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSSelectorParser.h"

static NSRegularExpression *const RX_COMBINATOR =
[NSRegularExpression regularExpressionWithPattern:@"^\\s*([\\s~+>]|/(.*?)/|!>)"
                                          options:0 error:NULL];

static NSRegularExpression *const RX_TYPE_SELECTOR =
[NSRegularExpression regularExpressionWithPattern:@"^\\s*(\\*|[^\\W\\d][\\w\\-]*)"
                                          options:0 error:NULL];

static NSRegularExpression *const RX_ATTR_SELECTOR =   //   1          23         4       5
[NSRegularExpression regularExpressionWithPattern:@"^\\s*\\[([\\w\\-]+)(([~^$*]?)=([\"']?)(.*?)\\4)?]"
                                          options:0 error:NULL];

static NSRegularExpression *const RX_SELECTOR_START =
[NSRegularExpression regularExpressionWithPattern:@"^\\s*:([\\w\\-]+)(\\()?"
                                          options:0 error:NULL];

static NSRegularExpression *const RX_ID_SELECTOR =
[NSRegularExpression regularExpressionWithPattern:@"^\\s*([.#])([^\\W\\d]\\w*)"
                                          options:0 error:NULL];

static NSRegularExpression *const RX_SUBJECTOR =
[NSRegularExpression regularExpressionWithPattern:@"^\\s*!"
                                          options:0 error:NULL];

// ^SFCSSFilter*(SFSelectorParser*)
static auto *const g_UserFilters = NSMutableDictionary.dictionary;

@implementation SFCSSSelectorParser
{
    SFSelectorChain *_subject;
}

+ (void)addFilter:(NSString*)name
             with:(SFCSSFilter*(^)(SFCSSSelectorParser*))parsec
{
    // NSLog(@"SFSelectorParser.addFilter: name=%@", name);
    // てけとー<(^_^;)
    g_UserFilters[name] = parsec;
}

- (instancetype)initWithQuery:(NSString*)query
{
    if ((self = [super init])) {
        self.source = query;
    }
    return self;
}

- (SFSelectorChain*)parse
{
    auto head = [SFSelectorChain.alloc init];
    [self parseSubject:head];
    while ([self scan:RX_COMBINATOR]) {
        auto kind = (Combinator) [[self $:1] characterAtIndex:0];
        head = [SFSelectorChain.alloc initWithTail:head];
        head->combinator = kind;
        head->idref = kind == COMB_IDREF ? [self $:2]: nil;
        [self parseSubject:head];
    }
    return head;
}

+ (SFSelectorChain*)parse:(NSString*)query
{
    return [[SFCSSSelectorParser.alloc initWithQuery:query] parse];
}

- (SFCSSFilter*)parseFilter
{
    if (![self scan:RX_SELECTOR_START]) {
        return nil;
    } 
    SFCSSFilter* (^parsec)(SFCSSSelectorParser*) = g_UserFilters[[self $:1]];
    if (!parsec) {
        [self raiseError:[NSString stringWithFormat:@"Unknown filter name:%@", [self $:1]]];
    }
    if (![self $:2].length) { // 引数なし
        return parsec(nil);
    }
    auto filter = parsec(self);
    if (self.code != ')') {
        [self raiseError:[NSString stringWithFormat:@"Expected `)', but `%c' found.", self.code]];
    }
    ++self.cursor;
    return filter;
}

- (void)parseSubject:(SFSelectorChain*)head
{
    if ([self scan:RX_SUBJECTOR]) {
        if (_subject) {
            [self raiseError:@"Duplicated `!' subjector."];
        }
        _subject = head;
    }
    head->filter = [self parseSelector];
}

- (SFCSSFilter*)parseSelector
{
    SFCSSFilter *head = nil;
    SFCSSFilter *tail = nil;
    if ([self scan:RX_TYPE_SELECTOR]) {
        head = [SFTypeSelector.alloc initWithName:[self $:1]];
        tail = head;
    }
    for (SFCSSFilter *next;; ) {
        if ((next = [self parseFilter])) {
            // no-op
        }
        else if ([self scan:RX_ATTR_SELECTOR]) {
            next = [self $:2].length
            ? [SFAttributeFilter.alloc initWithName:[self $:1]
                                           withData:[self $:5]
                                           withKind:[self $:3].length
                    ? MatchType([[self $:3] characterAtIndex:0])
                    : MATCH_EQUAL]
            : [SFAttributeFilter.alloc initWithName:[self $:1]
                                           withData:@""
                                           withKind:MATCH_PREFIX];
        }
        else if ([self scan:RX_ID_SELECTOR]) {
            next = [[self $:1] isEqualToString:@"."]
            ? [SFAttributeFilter.alloc initWithName:@"class"
                                           withData:[self $:2]
                                           withKind:MATCH_EQUAL_PART]
            : [SFAttributeFilter.alloc initWithName:@"id"
                                           withData:[self $:2]
                                           withKind:MATCH_EQUAL];
        }
        else {
            break;
        }
        tail = (head ? tail->next: head) = next;
    }
    return head;
}

- (void)raiseError:(NSString*)message
{
    [NSException raise:@"SFCSSelectorSyntaxError" format:@"%@", message];
}

@end

