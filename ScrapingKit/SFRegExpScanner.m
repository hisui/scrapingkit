//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFRegExpScanner.h"

@implementation SFRegExpScanner
{
    NSString *_source;
    NSInteger _cursor;
    
    // 最後にマッチした正規表現の結果を入れておく
    NSTextCheckingResult *_last;
}

- (void)setSource:(NSString*)source
{
    _source = source;
    _cursor = 0;
}

- (void)setCursor:(NSInteger)i
{
    if (i < _source.length) _cursor = i;
}

- (NSInteger)remaining
{
    return _source.length - _cursor;
}

- (unichar)code
{
    return [_source characterAtIndex:_cursor];
}

- (instancetype)initWith:(NSString*)data
{
    if ((self = [self init])) {
        self->_source = data;
    }
    return self;
}

- (NSTextCheckingResult*)scan:(NSRegularExpression*)pattern
{
    NSRange next = NSMakeRange(_cursor, _source.length - _cursor);
    if (( _last = [pattern firstMatchInString:_source options:0 range:next])
       && _last.range.location != NSNotFound)
    {
        _cursor += _last.range.length;
    }
    return _last;
}

- (NSString*)$:(int)n
{
    NSRange range = [_last rangeAtIndex:n];
    if (range.location == NSNotFound) {
        return nil;
    }
    return [_source substringWithRange:[_last rangeAtIndex:n]];
}

- (NSRange)rangeAtIndex:(int)n
{
    return [_last rangeAtIndex:n];
}

@end
