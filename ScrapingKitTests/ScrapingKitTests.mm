//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "ScrapingKitTests.h"
#import "SFDocument.h"
#import "SFNodeList+Dot.h"

static NSString *SAMPLE_HTML = @
"<html>"
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
"        <li id='c'>C&amp;</li>"
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

@implementation ScrapingKitTests

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testSampleCode
{
    NSLog(@"-------------------------");
    auto all = [SFNodeList nodeListWithHTML:SAMPLE_HTML];
    all.find(@"ul")
    .children
    .next
    .next
    .forEach(^(SFElement *e) {
        NSLog(@"elem:%@", e);
    });
    NSLog(@"-------------------------");
}

@end
