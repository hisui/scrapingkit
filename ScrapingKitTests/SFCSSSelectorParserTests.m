//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSSelectorParserTests.h"
#import "SFCSSSelectorParser+Test.h"
#import "SFCSSFilter.h"

@implementation SFCSSSelectorParserTests

- (void)testParseTypeSelector
{

    STAssertEqualObjects
    (@"<[a]>", [self dumpFileters:[[self newParser:@"a"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[*]>", [self dumpFileters:[[self newParser:@"*"] parseSelector]], nil);

    // empty string
    STAssertEqualObjects
    (@"<>", [self dumpFileters:[[self newParser:@""] parseSelector]], nil);

}

- (void)testParseIdAndClassFilter
{
    
    STAssertEqualObjects
    (@"<[a][[class~='x']]>", [self dumpFileters:[[self newParser:@"a.x"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[[class~='x']]>", [self dumpFileters:[[self newParser:@".x"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[id='x']]>", [self dumpFileters:[[self newParser:@"a#x"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[[id='x']]>", [self dumpFileters:[[self newParser:@"#x"] parseSelector]], nil);
    
}

- (void)testParseAttributeFilter
{
    
    STAssertEqualObjects
    (@"<[a][[x='y']]>", [self dumpFileters:[[self newParser:@"a[x=y]"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[[x='y']]>", [self dumpFileters:[[self newParser:@"[x=y]"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[x^='y']]>", [self dumpFileters:[[self newParser:@"a[x^=y]"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[x$='y']]>", [self dumpFileters:[[self newParser:@"a[x$=y]"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[x*='y']]>", [self dumpFileters:[[self newParser:@"a[x*=y]"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[x~='y']]>", [self dumpFileters:[[self newParser:@"a[x~=y]"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[x='y']]>", [self dumpFileters:[[self newParser:@"a[x='y']"] parseSelector]], nil);
    
    STAssertEqualObjects
    (@"<[a][[x='y']]>", [self dumpFileters:[[self newParser:@"a[x=\"y\"]"] parseSelector]], nil);

}

- (void)testParseNthXXXFilter
{
    
    STAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]], nil);
    
    // 残り分
    
    STAssertEqualObjects
    (@"<[:nth-last-child(0n+1)]>", [self dumpFileters:[[self newParser:@":nth-last-child(1)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-of-type(0n+1)]>", [self dumpFileters:[[self newParser:@":nth-of-type(1)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-last-of-type(0n+1)]>", [self dumpFileters:[[self newParser:@":nth-last-of-type(1)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-child(0n+0)]>", [self dumpFileters:[[self newParser:@":first-child"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:nth-last-child(0n+0)]>", [self dumpFileters:[[self newParser:@":last-child"] parseFilter]], nil);

}

- (void)testParseNotFilters
{
    
    STAssertEqualObjects
    (@"<[:not(*:empty)]>", [self dumpFileters:[[self newParser:@":not(*:empty)"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:not(:empty)]>", [self dumpFileters:[[self newParser:@":not(:empty)"] parseFilter]], nil);
}

- (void)testParseAllFilters
{
    
    STAssertEqualObjects
    (@"<[:empty]>", [self dumpFileters:[[self newParser:@":empty"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:blank]>", [self dumpFileters:[[self newParser:@":blank"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:root]>", [self dumpFileters:[[self newParser:@":root"] parseFilter]], nil);
    
    STAssertEqualObjects
    (@"<[:base]>", [self dumpFileters:[[self newParser:@":base"] parseFilter]], nil);
    
}

- (void)testParseCompoundSelector
{
    
    STAssertEqualObjects
    (@"<[a][[class~='x']][[id='y']][[a='b']][:nth-child(2n+1)]>"
     , [self dumpFileters:[[self newParser:@"a.x#y[a=b]:nth-child(2n+1)"] parseSelector]], nil);

}

- (void)testParseCombinator
{
    
    STAssertEqualObjects
    (@"<[a][[class~='x']][[id='y']][[a='b']]>"
     , [self dumpFileters:[[self newParser:@"a.x#y[a=b]"] parseSelector]], nil);
    
}

- (NSString*)dumpFileters:(SFCSSFilter*)head
{
    NSMutableString *buf = NSMutableString.string;
    while (head) {
        [buf appendFormat:@"[%@]", head.dump];
        head = head->next;
    }
    return [NSString stringWithFormat:@"<%@>", buf];
}

- (SFCSSSelectorParser*)newParser:(NSString*)q
{
    return [[SFCSSSelectorParser alloc] initWithQuery:q];
}

@end
