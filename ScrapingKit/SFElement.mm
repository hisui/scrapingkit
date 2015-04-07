//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import "SFElement.h"
#import "SFText.h"
#import "SFNode+Local.h"
#import "SFCSSQuery.h"

static BOOL isText(SFNode *node)
{
    return ![node isMemberOfClass:[SFElement class]];
}

@implementation SFElement
{

    NSString *_name;
    NSMutableDictionary *_attributes;
    
    // 子ノードのリスト
    SFNode *_first;
    SFNode *_guard;
    size_t _size;
    
    // 要素間リンク
    SFElement *_prevElem __unsafe_unretained;
    SFElement *_nextElem __unsafe_unretained;
    
    // ノードの（親からみた）位置情報
    int _nodeIndex;
    int _typeIndex;
    int _lastNodeIndex;
    int _lastTypeIndex;

    BOOL _changed;

}

@synthesize nextElement = _nextElem;
@synthesize prevElement = _prevElem;

- (NSString*)text
{
    switch (_size) {
    case 1: return _first.text;
    case 0: return @"";
    }
    auto buf = NSMutableString.string;
    for (auto cur = _first; cur != _guard; cur = cur->_next) {
        [buf appendString:cur.text];
    }
    return buf;
}

- (void)setText:(NSString*)text
{
    [self removeAll];
    [self append:[SFText.alloc initWithText:text]];
}

- (instancetype)init
{
    if ((self = [super init])) {
        self->_name = @"(*_*) bug?";
        self->_first = [SFNode.alloc init];
        self->_guard = _first;
        self->_attributes = NSMutableDictionary.dictionary;
    }
    return self;
}

- (instancetype)initWithName:(NSString *)name
{
    if ((self = [self init])) {
        self->_name = [name copy];
    }
    return self;
}

- (instancetype)initWithName:(NSString*)name attrs:(NSDictionary*)attributes
{
    if ((self = [self initWithName:name])) {
        self->_attributes = [attributes mutableCopy];
    }
    return self;
}

- (NSString*)description
{
    auto buf = [NSMutableString stringWithString:_name];
    for (NSString *key in _attributes) {
        [buf appendFormat:@" %@='%@'", key, _attributes[key]];
    }
    if (_size == 1 && isText(_first) && _first.text.length < 32) {
        return [NSString stringWithFormat:@"<%@>%@</%@>", buf, _first.text, _name];
    }
    return _size
    ? [NSString stringWithFormat:@"<%@> ... </%@>", buf, _name]
    : [NSString stringWithFormat:@"<%@/>", buf];
}

- (NSString*)stringify
{
    auto buf = [NSMutableString stringWithFormat:@"<%@", _name];
    for (NSString *key in _attributes) {
        [buf appendFormat:@" %@='%@'", key, SFTextEncode(_attributes[key])];
    }
    if (_size) {
        [buf appendString:@">"];
        for (auto cur = _first; cur != _guard; cur = cur->_next) {
            [buf appendString:cur.stringify];
        }
        [buf appendFormat:@"</%@>", _name];
    }
    else {
        [buf appendString:@"/>"];
    }
    return buf;
}


- (void)print:(int)indent
{
    NSString *pad = stringRepeatedAt(@"  ", indent);
    NSLog(@"[html] %@%@ {", pad, _name);
    for (auto cur = _first; cur != _guard; cur = cur->_next) {
        [cur print:indent + 1];
    }
    NSLog(@"[html] %@} // %@", pad, _name);
}

// readonly property
- (SFElement*)root
{
    SFElement *cur = self;
    while (cur.parent) {
        cur = cur.parent;
    }
    return cur;
}

// readonly property
- (NSDictionary*)attributes
{
    return _attributes.copy;
}

// readonly property
- (SFNode*)first
{
    return _first != _guard ? _first: nil;
}

// readonly property
- (SFElement*)firstElement
{
    for (auto cur = _first; cur != _guard; cur = cur->_next) {
        if (!isText(cur)) {
            return (SFElement*) cur;
        }
    }
    return nil;
}

// readonly property
- (int)nodeIndex
{
    if (!_parent) return -1;
    if ( _parent->_changed) [_parent updateIndex];
    return _nodeIndex;
}

// readonly property
- (int)typeIndex
{
    if (!_parent) return -1;
    if ( _parent->_changed) [_parent updateIndex];
    return _typeIndex;
}

// readonly property
- (int)lastNodeIndex
{
    if (!_parent) return -1;
    if ( _parent->_changed) [_parent updateIndex];
    return _lastNodeIndex;
}

// readonly property
- (int)lastTypeIndex
{
    if (!_parent) return -1;
    if ( _parent->_changed) [_parent updateIndex];
    return _lastTypeIndex;
}

// readonly property
- (NSArray*)descendant
{
    auto a = NSMutableArray.array;
    void (^callee)(SFElement*) __block = nullptr;
    void (^append)(SFElement*) __block = ^(SFElement *elem) {
        for (auto cur = elem.firstElement; cur; cur = cur->_nextElem) {
            [a addObject:cur];
            callee(cur);
        }
    };
    (callee = append)(self);
    append = nullptr;
    callee = nullptr;
    return a;
}

- (void)append:(SFNode*)node
{
    [self insert:node before:nil];
}

- (void)insert:(SFNode*)node
        before:(SFNode*)dest
{
    if (!dest) {
        dest = _guard;
    }
    else if (dest->_parent != self) {
        return;
    }
    if (node->_parent) {
        if (self == node->_parent) {
            return;
        }
        [node->_parent remove:node];
    }
    if (!isText(node)) {
        auto elem = (SFElement*) node;
        SFElement *prev = nil;
        SFElement *next = nil;
        for (auto t=dest->_prev; t; t=t->_prev) if (!isText(t)) { prev = (SFElement*)t; break; }
        for (auto t=dest       ; t; t=t->_next) if (!isText(t)) { next = (SFElement*)t; break; }
        if (prev) {
            NSAssert(prev->_nextElem == next, @"");
            prev->_nextElem = elem;
            elem->_prevElem = prev;
        }
        if (next) {
            NSAssert(next->_prevElem == prev, @"");
            next->_prevElem = elem;
            elem->_nextElem = next;
        }
    }
    node->_parent = self;
    node->_next = dest;
    node->_prev = dest->_prev;
    if (dest->_prev) {
        dest->_prev->_next = node;
    }
    else {
        _first = node;
    }
    dest->_prev = node;
    ++_size;
    _changed = YES;
}

- (BOOL)remove:(SFNode*)node
{
    if (node->_parent != self) {
        return NO;
    }
    NSAssert(node != _guard && node->_next, @"Cannot remove a gurad!");
    if (!isText(node)) {
        auto elem = (SFElement*) node;
        if (elem->_prevElem) elem->_prevElem->_nextElem = elem->_nextElem;
        if (elem->_nextElem) elem->_nextElem->_prevElem = elem->_prevElem;
        elem->_prevElem = nil;
        elem->_nextElem = nil;
    }
    if ((node->_next->_prev = node->_prev)) {
        node->_prev->_next = node->_next;
    }
    else {
        _first = node->_next;
    }
    node->_parent = nil;
    node->_prev = nil;
    node->_next = nil;
    --_size;
    _changed = YES;
    return YES;
}

- (void)removeAll
{
    _size = 0, _changed = YES;
    // _prevは弱参照(_nextは強参照)なので逆方向から
    for (auto node = _guard; node; node = node->_prev) {
        node->_parent = nil;
        node->_prev = nil;
        node->_next = nil;
        if (!isText(node)) {
            auto elem = (SFElement*) node;
            elem->_prevElem = nil;
            elem->_nextElem = nil;
        }
    }
    _first = _guard;
}

- (BOOL)contains:(SFNode*)node
{
    for (auto cur = node.parent; cur; cur = cur.parent) {
        if (cur == self) {
            return YES;
        }
    }
    return NO;
}

- (NSString*)get:(NSString*)key
{
    return _attributes[key];
}

- (void)set:(NSString*)value
     forKey:(NSString*)key
{
    if (!value) {
        [_attributes removeObjectForKey:key];
        return;
    }
    _attributes[key] = value;
}

- (SFElement*)find:(NSString*)query
{
    return [[SFCSSQuery query:query] find1st:self];
}

- (id <NSFastEnumeration>)filter:(NSString*)query
{
    
    return [[SFCSSQuery query:query] findAll:self];
}

- (void)updateIndex
{
    NSString *name = nil;
    int i = 0;
    int j = 0;
    SFElement *last = nil;
    for (auto cur = self.firstElement; cur; cur = cur->_nextElem) {
        last = cur;
        cur->_nodeIndex = i++;
        cur->_typeIndex = 0;
        if ([name isEqual:cur->_name]) {
            cur->_typeIndex = ++j;
            continue;
        }
        name = cur->_name;
        j = 0;
    }
    i = 0;
    j = 0;
    for (auto cur = last; cur; cur = cur->_prevElem) {
        cur->_lastNodeIndex = i++;
        if (!cur->_typeIndex) {
            j = 0;
        }
        cur->_lastTypeIndex = j++;
    }
    _changed = NO;
}

@end
