//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFCSSQueryTests.h"
#import "SFCSSQuery+Local.h"
#import "SFDocument+Local.h"

static NSString *TEST_HTML =
@"<html>"
 "  <head>"
 "    <meta data='AAA'/>"
 "    <meta data='BBB'/>"
 "    <title>test</title>"
 "  </head>"
 "  <body>"
 "    <h1>header</h1>"
 "    <div id='content'>"
 "      <ul id='list_a'>"
 "        <li id='a'>A</li>"
 "        <li id='b'>B</li>"
 "        <li id='c'>C</li>"
 "      </ul>"
 "      <ul id='list_b'>"
 "        <li for='a'>1</li>"
 "        <li for='c'>2</li>"
 "      </ul>"
 "    </div>"
 "    <div id='footer'>"
 "      <div id='box_W'/>"
 "      <div id='box_X'/>"
 "      <div id='box_Y'/>"
 "      <div id='box_Z'/>"
 "    </div>"
 "    <a name='foot'>\t \r\n</a>"
 "  </body>"
 "</html>";

@implementation SFCSSQueryTests
{
    SFDocument *_doc;
}

- (void)setUp
{
    _doc = [SFDocument documentWithHTML:TEST_HTML];
}

- (void)testSimpleQueries
{
    
    // 単一のタグを選択
    XCTAssertEqualObjects
    (@[@"<title>test</title>"], [self querySelectorAll:@"title"]);
    
    // ルートを選択
    XCTAssertEqualObjects
    (@[@"<html> ... </html>"], [self querySelectorAll:@"html"]);
    
    // 複数のタグを選択
    XCTAssertEqualObjects
    ((@[@"<ul id='list_a'> ... </ul>"
      , @"<ul id='list_b'> ... </ul>"]), [self querySelectorAll:@"ul"]);
    
    // 空のタグを選択
    XCTAssertEqualObjects
    ((@[@"<meta data='AAA'/>"
      , @"<meta data='BBB'/>"
      , @"<div id='box_W'/>"
      , @"<div id='box_X'/>"
      , @"<div id='box_Y'/>"
      , @"<div id='box_Z'/>"]), [self querySelectorAll:@"*:empty"]);
    
    // 空欄のタグを選択(emptyはじゃまなので弾く)
    XCTAssertEqualObjects
    ((@[@"<a name='foot'>\t \r\n</a>"]), [self querySelectorAll:@"*:blank:not(*:empty)"]);

}

- (void)testQueriesWithCombinator
{
    
    // 親子関係
    XCTAssertEqualObjects
    ((@[@"<title>test</title>"]), [self querySelectorAll:@"head>title"]);
    
    XCTAssertEqualObjects
    ((@[@"<head> ... </head>"]), [self querySelectorAll:@"!head>title"]);
    
    // 祖先関係
    XCTAssertEqualObjects
    ((@[@"<title>test</title>"]), [self querySelectorAll:@"html title"]);

    XCTAssertEqualObjects
    ((@[@"<html> ... </html>"]), [self querySelectorAll:@"!html title"]);
    
    XCTAssertEqualObjects
    ((@[@"<li for='a'>1</li>"
      , @"<li for='c'>2</li>"]), [self querySelectorAll:@"ul#list_b li"]);
    
    // 兄弟関係
    XCTAssertEqualObjects
    ((@[@"<body> ... </body>"]), [self querySelectorAll:@"head+*"]);
    
    XCTAssertEqualObjects
    ((@[@"<head> ... </head>"]), [self querySelectorAll:@"!*+body"]);
    
    XCTAssertEqualObjects
    ((@[@"<html> ... </html>"]), [self querySelectorAll:@"!html title"]);
    
    XCTAssertEqualObjects
    ((@[@"<li id='b'>B</li>"
      , @"<li id='c'>C</li>"]), [self querySelectorAll:@"ul#list_a>li~*"]);
    
    XCTAssertEqualObjects
    ((@[@"<li id='a'>A</li>"
      , @"<li id='b'>B</li>"]), [self querySelectorAll:@"ul#list_a>!li~*"]);
    
    // 参照関係
    XCTAssertEqualObjects
    ((@[@"<li id='a'>A</li>"
      , @"<li id='c'>C</li>"]), [self querySelectorAll:@"li /for/ li"]);

    XCTAssertEqualObjects
    ((@[@"<li for='a'>1</li>"
      , @"<li for='c'>2</li>"]), [self querySelectorAll:@"!li /for/ li"]);

}

- (void)testNthChild
{
    
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_X'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(1)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_Z'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_W'/>"
      , @"<div id='box_Y'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(even)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_X'/>"
      , @"<div id='box_Z'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(odd)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_W'/>"
      , @"<div id='box_Z'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3n)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_X'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3n+1)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_Y'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3n-1)"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_W'/>"
      , @"<div id='box_X'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(-n+1)"]);
    
}

- (void)testComplexQueries
{
    
    XCTAssertEqualObjects
    ((@[@"<ul id='list_a'> ... </ul>"
      , @"<ul id='list_b'> ... </ul>"]), [self querySelectorAll:@"!ul>li+li"]);
    
    XCTAssertEqualObjects
    ((@[@"<ul id='list_a'> ... </ul>"]), [self querySelectorAll:@"!ul>li+li+li"]);
    
    XCTAssertEqualObjects
    ((@[@"<div id='box_Z'/>"]), [self querySelectorAll:@"div>#box_X+*~*" ]);

}

- (NSArray*)querySelectorAll:(NSString*)q
{
    fprintf(stderr, "query(%s) {\n", q.UTF8String);
    NSMutableArray *a = [NSMutableArray array];
    for (SFElement *e in [[SFCSSQuery query:q] findAll:_doc]) {
        [a addObject:e.description];
        fprintf(stderr, "\t%s\n", [a.lastObject UTF8String]);
    }
    fprintf(stderr, "}\n\n");
    return a;
}

@end
