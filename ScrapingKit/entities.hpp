//  Copyright (c) 2013 segfault.jp. All rights reserved.

#ifndef SFL_HTML_ENTITIES_HPP
#define SFL_HTML_ENTITIES_HPP

#include <algorithm>
#include "./unicode.hpp"

namespace sf {

template<typename II>
bool htmlentity_decode_next(II &pos, II end, uint32_t &c)
{
    static const uint32_t l[] = {'&', ';'};
    auto i = std::find(pos, end, *l);
    auto j = i;
    if (i == end) return false;
    do {
        if ((std::find_first_of(++j, end, l, l+2)) == end) {
            return false;
        }
    } while (*j == '&');
    c = htmlentity_by_name(++i, j);
    return true;
}

// TODO
template<typename II>
uint32_t htmlentity_code_by_name(II pos, II end)
{
    basic_scanner<II> i(pos, end);
    if (i.get() == '#') {
    }
    return 0;
}
    
}

#endif
