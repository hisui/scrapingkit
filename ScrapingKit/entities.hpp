//  Copyright (c) 2013 segfault.jp. All rights reserved.

#ifndef SFL_HTML_ENTITIES_HPP
#define SFL_HTML_ENTITIES_HPP

#include <algorithm>
#include "./unicode.hpp"

namespace sf {
    namespace detail {
        #include "./entities.cpp"
    }

    template<typename InputIterator>
    InputIterator htmlentity_decode_next(InputIterator &pos, InputIterator end, uint32_t &ord)
    {
        auto i = pos;
        for (;;) {
            if ((i = std::find(i, end, '&')) == end) return end;
            auto j = i;
            auto k = std::find(++i, end, ';');
            if (k != end) {
                ord = htmlentity_decode(i, k);
                pos = ++k;
                return j;
            }
        }
    }

    // TODO
    template<typename InputIterator>
    uint32_t htmlentity_decode(InputIterator pos, InputIterator end)
    {
        basic_scanner<InputIterator> i(pos, end);
        if (i.get() == '#') {
        }
        return detail::ascii_to_code(pos, end);
    }
    
} // namespace

#endif
