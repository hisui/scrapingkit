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
    STAssertEqualObjects
    (@[@"<title>test</title>"], [self querySelectorAll:@"title"], nil);
    
    // ルートを選択
    STAssertEqualObjects
    (@[@"<html> ... </html>"], [self querySelectorAll:@"html"], nil);
    
    // 複数のタグを選択
    STAssertEqualObjects
    ((@[@"<ul id='list_a'> ... </ul>"
      , @"<ul id='list_b'> ... </ul>"]), [self querySelectorAll:@"ul"], nil);
    
    // 空のタグを選択
    STAssertEqualObjects
    ((@[@"<meta data='AAA'/>"
      , @"<meta data='BBB'/>"
      , @"<div id='box_W'/>"
      , @"<div id='box_X'/>"
      , @"<div id='box_Y'/>"
      , @"<div id='box_Z'/>"]), [self querySelectorAll:@"*:empty"], nil);
    
    // 空欄のタグを選択(emptyはじゃまなので弾く)
    STAssertEqualObjects
    ((@[@"<a name='foot'>\t \r\n</a>"]), [self querySelectorAll:@"*:blank:not(*:empty)"], nil);

}

- (void)testQueriesWithCombinator
{
    
    // 親子関係
    STAssertEqualObjects
    ((@[@"<title>test</title>"]), [self querySelectorAll:@"head>title"], nil);
    
    STAssertEqualObjects
    ((@[@"<head> ... </head>"]), [self querySelectorAll:@"!head>title"], nil);
    
    // 祖先関係
    STAssertEqualObjects
    ((@[@"<title>test</title>"]), [self querySelectorAll:@"html title"], nil);

    STAssertEqualObjects
    ((@[@"<html> ... </html>"]), [self querySelectorAll:@"!html title"], nil);
    
    STAssertEqualObjects
    ((@[@"<li for='a'>1</li>"
      , @"<li for='c'>2</li>"]), [self querySelectorAll:@"ul#list_b li"], nil);
    
    // 兄弟関係
    STAssertEqualObjects
    ((@[@"<body> ... </body>"]), [self querySelectorAll:@"head+*"], nil);
    
    STAssertEqualObjects
    ((@[@"<head> ... </head>"]), [self querySelectorAll:@"!*+body"], nil);
    
    STAssertEqualObjects
    ((@[@"<html> ... </html>"]), [self querySelectorAll:@"!html title"], nil);
    
    STAssertEqualObjects
    ((@[@"<li id='b'>B</li>"
      , @"<li id='c'>C</li>"]), [self querySelectorAll:@"ul#list_a>li~*"], nil);
    
    STAssertEqualObjects
    ((@[@"<li id='a'>A</li>"
      , @"<li id='b'>B</li>"]), [self querySelectorAll:@"ul#list_a>!li~*"], nil);
    
    // 参照関係
    STAssertEqualObjects
    ((@[@"<li id='a'>A</li>"
      , @"<li id='c'>C</li>"]), [self querySelectorAll:@"li /for/ li"], nil);

    STAssertEqualObjects
    ((@[@"<li for='a'>1</li>"
      , @"<li for='c'>2</li>"]), [self querySelectorAll:@"!li /for/ li"], nil);

}

- (void)testNthChild
{
    
    
    STAssertEqualObjects
    ((@[@"<div id='box_X'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(1)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_Z'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_W'/>"
      , @"<div id='box_Y'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(even)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_X'/>"
      , @"<div id='box_Z'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(odd)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_W'/>"
      , @"<div id='box_Z'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3n)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_X'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3n+1)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_Y'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(3n-1)"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_W'/>"
      , @"<div id='box_X'/>"]), [self querySelectorAll:@"*#footer>div:nth-child(-n+1)"], nil);
    
}

- (void)testComplexQueries
{
    
    STAssertEqualObjects
    ((@[@"<ul id='list_a'> ... </ul>"
      , @"<ul id='list_b'> ... </ul>"]), [self querySelectorAll:@"!ul>li+li"], nil);
    
    STAssertEqualObjects
    ((@[@"<ul id='list_a'> ... </ul>"]), [self querySelectorAll:@"!ul>li+li+li"], nil);
    
    STAssertEqualObjects
    ((@[@"<div id='box_Z'/>"]), [self querySelectorAll:@"div>#box_X+*~*" ], nil);

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
