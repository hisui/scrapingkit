//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import <XCTest/XCTest.h>
#import "SFDocument+Local.h"

@interface SFDocumentTests : XCTestCase

@end

@implementation SFDocumentTests

- (void)testSimple
{
    auto root = [SFDocument documentWithHTML:@"<html>&nbsp;</html>"];
    auto html = root.firstElement;
    XCTAssertEqualObjects(@"html", html.name);

    auto data = [html.text dataUsingEncoding:NSUTF16StringEncoding];
    XCTAssertEqual(4, data.length); // + BOM
    XCTAssertEqual(0xfeff, ((uint16_t*)data.bytes)[0]);
    XCTAssertEqual(0x00A0, ((uint16_t*)data.bytes)[1]);
}

@end
