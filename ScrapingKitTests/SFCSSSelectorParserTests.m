//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSSelectorParserTests.h"
#import "SFCSSSelectorParser+Test.h"
#import "SFCSSFilter.h"

@implementation SFCSSSelectorParserTests

- (void)testParseTypeSelector
{

    XCTAssertEqualObjects
    (@"<[a]>", [self dumpFileters:[[self newParser:@"a"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[*]>", [self dumpFileters:[[self newParser:@"*"] parseSelector]]);

    // empty string
    XCTAssertEqualObjects
    (@"<>", [self dumpFileters:[[self newParser:@""] parseSelector]]);

}

- (void)testParseIdAndClassFilter
{
    
    XCTAssertEqualObjects
    (@"<[a][[class~='x']]>", [self dumpFileters:[[self newParser:@"a.x"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[[class~='x']]>", [self dumpFileters:[[self newParser:@".x"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[id='x']]>", [self dumpFileters:[[self newParser:@"a#x"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[[id='x']]>", [self dumpFileters:[[self newParser:@"#x"] parseSelector]]);
    
}

- (void)testParseAttributeFilter
{
    
    XCTAssertEqualObjects
    (@"<[a][[x='y']]>", [self dumpFileters:[[self newParser:@"a[x=y]"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[[x='y']]>", [self dumpFileters:[[self newParser:@"[x=y]"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[x^='y']]>", [self dumpFileters:[[self newParser:@"a[x^=y]"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[x$='y']]>", [self dumpFileters:[[self newParser:@"a[x$=y]"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[x*='y']]>", [self dumpFileters:[[self newParser:@"a[x*=y]"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[x~='y']]>", [self dumpFileters:[[self newParser:@"a[x~=y]"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[x='y']]>", [self dumpFileters:[[self newParser:@"a[x='y']"] parseSelector]]);
    
    XCTAssertEqualObjects
    (@"<[a][[x='y']]>", [self dumpFileters:[[self newParser:@"a[x=\"y\"]"] parseSelector]]);

}

- (void)testParseNthXXXFilter
{
    
    XCTAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-child(0n+3)]>", [self dumpFileters:[[self newParser:@":nth-child(3)"] parseFilter]]);
    
    // 残り分
    
    XCTAssertEqualObjects
    (@"<[:nth-last-child(0n+1)]>", [self dumpFileters:[[self newParser:@":nth-last-child(1)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-of-type(0n+1)]>", [self dumpFileters:[[self newParser:@":nth-of-type(1)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-last-of-type(0n+1)]>", [self dumpFileters:[[self newParser:@":nth-last-of-type(1)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-child(0n+0)]>", [self dumpFileters:[[self newParser:@":first-child"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:nth-last-child(0n+0)]>", [self dumpFileters:[[self newParser:@":last-child"] parseFilter]]);

}

- (void)testParseNotFilters
{
    
    XCTAssertEqualObjects
    (@"<[:not(*:empty)]>", [self dumpFileters:[[self newParser:@":not(*:empty)"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:not(:empty)]>", [self dumpFileters:[[self newParser:@":not(:empty)"] parseFilter]]);
}

- (void)testParseAllFilters
{
    
    XCTAssertEqualObjects
    (@"<[:empty]>", [self dumpFileters:[[self newParser:@":empty"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:blank]>", [self dumpFileters:[[self newParser:@":blank"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:root]>", [self dumpFileters:[[self newParser:@":root"] parseFilter]]);
    
    XCTAssertEqualObjects
    (@"<[:base]>", [self dumpFileters:[[self newParser:@":base"] parseFilter]]);
    
}

- (void)testParseCompoundSelector
{
    
    XCTAssertEqualObjects
    (@"<[a][[class~='x']][[id='y']][[a='b']][:nth-child(2n+1)]>"
     , [self dumpFileters:[[self newParser:@"a.x#y[a=b]:nth-child(2n+1)"] parseSelector]]);

}

- (void)testParseCombinator
{
    
    XCTAssertEqualObjects
    (@"<[a][[class~='x']][[id='y']][[a='b']]>"
     , [self dumpFileters:[[self newParser:@"a.x#y[a=b]"] parseSelector]]);
    
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
    return [SFCSSSelectorParser.alloc initWithQuery:q];
}

@end
