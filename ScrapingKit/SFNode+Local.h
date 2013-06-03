//  Copyright (c) 2013 segfault.jp. All rights reserved.

#import <Foundation/Foundation.h>

@interface SFNode ()
{
@public
    SFElement *_parent __unsafe_unretained;
    SFNode *_prev __unsafe_unretained;
    SFNode *_next;
}
@end
