//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFText.h"

NSString *SFTextEncode(NSString *src)
{
    const char *pos = [src cStringUsingEncoding:NSUTF8StringEncoding];
    const char *tmp = pos;
    NSMutableString *dest = [NSMutableString stringWithCapacity:strlen(pos)];
    while(*pos) {
        NSString *esc = nil;
        switch(*pos) {
        case '\'': esc = @"&apos;"; break;
        case  '"': esc = @"&qout;"; break;
        case  '&': esc =  @"&amp;"; break;
        case  '<': esc =   @"&lt;"; break;
        case  '>': esc =   @"&gt;"; break;
        default:
            ++pos;
            continue;
        }
        [dest appendString:
         [[NSString alloc] initWithBytesNoCopy:(char*)tmp
                                        length:pos - tmp
                                      encoding:NSUTF8StringEncoding      
                                  freeWhenDone:NO]];
        tmp = ++pos;
        [dest appendString:esc];
    }
    if(pos > tmp) {
        [dest appendString:
         [[NSString alloc] initWithBytesNoCopy:(char*)tmp
                                        length:pos - tmp
                                      encoding:NSUTF8StringEncoding
                                  freeWhenDone:NO]];
    }
    return dest;
}

NSString *SFTextDecode(NSString *src)
{
    return src;
}

@implementation SFText
{
    NSString *_text;
}
@synthesize text = _text;

- (id)initWithText:(NSString*)text
{
    if((self = [self init])) {
        self->_text = text.copy;
    }
    return self;
}

- (NSString*)stringify { return SFTextEncode(_text); }

- (BOOL)isBlank
{
    for (const char *p = _text.UTF8String; *p; ++p) {
        switch (*p) {
        default: return NO;
        case '\r':
        case '\n':
        case '\t':
        case  ' ':;
        }
    }
    return YES;
}

@end
