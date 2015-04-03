#include "tags.hpp"
#include <algorithm>

template <size_t N, typename InputIterator> bool is_prefix_of(const char (&src)[N], InputIterator pos, InputIterator end)
{
    for (int i = 0; i < N-1; ++i) {
        if (pos == end || *pos++ != src[i]) return false;
    }
    return true;
}

namespace sf {

template <typename InputIterator>
Tag ascii_to_Tag(InputIterator pos, InputIterator end)
{
    if (pos == end) return Tag_0;
    switch (*pos++) {
        case 'a':
            if (pos == end) return TAG_a;
            switch (*pos++) {
                case 'b':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("br", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_abbr;
                case 'c':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ronym", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    if (pos == end) return TAG_acronym;
                case 'd':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("dress", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    if (pos == end) return TAG_address;
                case 'p':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("plet", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_applet;
                case 'r':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ea", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_area;
            }
            return Tag_0;
        case 'b':
            if (pos == end) return TAG_b;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("se", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_base;
                    if (!is_prefix_of("font", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_basefont;
                case 'd':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'o') return Tag_0;
                    if (pos == end) return TAG_bdo;
                case 'i':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'g') return Tag_0;
                    if (pos == end) return TAG_big;
                case 'l':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ockquote", pos, end)) return Tag_0;
                    std::advance(pos, 8);
                    if (pos == end) return TAG_blockquote;
                case 'o':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("dy", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_body;
                case 'r':
                    if (pos == end) return TAG_br;
                case 'u':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("tton", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_button;
            }
            return Tag_0;
        case 'c':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ption", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    if (pos == end) return TAG_caption;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("nter", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_center;
                case 'i':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("te", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_cite;
                case 'o':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'd':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'e') return Tag_0;
                            if (pos == end) return TAG_code;
                        case 'l':
                            if (pos == end) return TAG_col;
                            if (!is_prefix_of("group", pos, end)) return Tag_0;
                            std::advance(pos, 5);
                            if (pos == end) return TAG_colgroup;
                    }
                    return Tag_0;
            }
            return Tag_0;
        case 'd':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'd':
                    if (pos == end) return TAG_dd;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'l') return Tag_0;
                    if (pos == end) return TAG_del;
                case 'f':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'n') return Tag_0;
                    if (pos == end) return TAG_dfn;
                case 'i':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'r':
                            if (pos == end) return TAG_dir;
                        case 'v':
                            if (pos == end) return TAG_div;
                    }
                    return Tag_0;
                case 'l':
                    if (pos == end) return TAG_dl;
                case 't':
                    if (pos == end) return TAG_dt;
            }
            return Tag_0;
        case 'e':
            if (pos == end) return Tag_0;
            if (*pos++ != 'm') return Tag_0;
            if (pos == end) return TAG_em;
        case 'f':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'i':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("eldset", pos, end)) return Tag_0;
                    std::advance(pos, 6);
                    if (pos == end) return TAG_fieldset;
                case 'o':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'n':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 't') return Tag_0;
                            if (pos == end) return TAG_font;
                        case 'r':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'm') return Tag_0;
                            if (pos == end) return TAG_form;
                    }
                    return Tag_0;
                case 'r':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ame", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_frame;
                    if (!is_prefix_of("set", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_frameset;
            }
            return Tag_0;
        case 'h':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case '1':
                    if (pos == end) return TAG_h1;
                case '2':
                    if (pos == end) return TAG_h2;
                case '3':
                    if (pos == end) return TAG_h3;
                case '4':
                    if (pos == end) return TAG_h4;
                case '5':
                    if (pos == end) return TAG_h5;
                case '6':
                    if (pos == end) return TAG_h6;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ad", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_head;
                case 'r':
                    if (pos == end) return TAG_hr;
                case 't':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ml", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_html;
            }
            return Tag_0;
        case 'i':
            if (pos == end) return TAG_i;
            switch (*pos++) {
                case 'f':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("rame", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_iframe;
                case 'm':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'g') return Tag_0;
                    if (pos == end) return TAG_img;
                case 'n':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'p':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("ut", pos, end)) return Tag_0;
                            std::advance(pos, 2);
                            if (pos == end) return TAG_input;
                        case 's':
                            if (pos == end) return TAG_ins;
                    }
                    return Tag_0;
                case 's':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("index", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    if (pos == end) return TAG_isindex;
            }
            return Tag_0;
        case 'k':
            if (pos == end) return Tag_0;
            if (!is_prefix_of("bd", pos, end)) return Tag_0;
            std::advance(pos, 2);
            if (pos == end) return TAG_kbd;
        case 'l':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("bel", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_label;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("gend", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_legend;
                case 'i':
                    if (pos == end) return TAG_li;
                    if (!is_prefix_of("nk", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_link;
            }
            return Tag_0;
        case 'm':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'p') return Tag_0;
                    if (pos == end) return TAG_map;
                case 'e':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'n':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'u') return Tag_0;
                            if (pos == end) return TAG_menu;
                        case 't':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'a') return Tag_0;
                            if (pos == end) return TAG_meta;
                    }
                    return Tag_0;
            }
            return Tag_0;
        case 'n':
            if (pos == end) return Tag_0;
            if (*pos++ != 'o') return Tag_0;
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'f':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("rames", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    if (pos == end) return TAG_noframes;
                case 's':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("cript", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    if (pos == end) return TAG_noscript;
            }
            return Tag_0;
        case 'o':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'b':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ject", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_object;
                case 'l':
                    if (pos == end) return TAG_ol;
                case 'p':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 't') return Tag_0;
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'g':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("roup", pos, end)) return Tag_0;
                            std::advance(pos, 4);
                            if (pos == end) return TAG_optgroup;
                        case 'i':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("on", pos, end)) return Tag_0;
                            std::advance(pos, 2);
                            if (pos == end) return TAG_option;
                    }
                    return Tag_0;
            }
            return Tag_0;
        case 'p':
            if (pos == end) return TAG_p;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ram", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_param;
                case 'r':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'e') return Tag_0;
                    if (pos == end) return TAG_pre;
            }
            return Tag_0;
        case 'q':
            if (pos == end) return TAG_q;
        case 's':
            if (pos == end) return TAG_s;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("mp", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_samp;
                case 'c':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ript", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_script;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("lect", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    if (pos == end) return TAG_select;
                case 'm':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("all", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_small;
                case 'p':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("an", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    if (pos == end) return TAG_span;
                case 't':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'r':
                            if (pos == end) return Tag_0;
                            switch (*pos++) {
                                case 'i':
                                    if (pos == end) return Tag_0;
                                    if (!is_prefix_of("ke", pos, end)) return Tag_0;
                                    std::advance(pos, 2);
                                    if (pos == end) return TAG_strike;
                                case 'o':
                                    if (pos == end) return Tag_0;
                                    if (!is_prefix_of("ng", pos, end)) return Tag_0;
                                    std::advance(pos, 2);
                                    if (pos == end) return TAG_strong;
                            }
                            return Tag_0;
                        case 'y':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("le", pos, end)) return Tag_0;
                            std::advance(pos, 2);
                            if (pos == end) return TAG_style;
                    }
                    return Tag_0;
                case 'u':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'b':
                            if (pos == end) return TAG_sub;
                        case 'p':
                            if (pos == end) return TAG_sup;
                    }
                    return Tag_0;
            }
            return Tag_0;
        case 't':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ble", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_table;
                case 'b':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ody", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_tbody;
                case 'd':
                    if (pos == end) return TAG_td;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("xtarea", pos, end)) return Tag_0;
                    std::advance(pos, 6);
                    if (pos == end) return TAG_textarea;
                case 'f':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("oot", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_tfoot;
                case 'h':
                    if (pos == end) return TAG_th;
                    if (!is_prefix_of("ead", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_thead;
                case 'i':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("tle", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    if (pos == end) return TAG_title;
                case 'r':
                    if (pos == end) return TAG_tr;
                case 't':
                    if (pos == end) return TAG_tt;
            }
            return Tag_0;
        case 'u':
            if (pos == end) return TAG_u;
            if (*pos++ != 'l') return Tag_0;
            if (pos == end) return TAG_ul;
        case 'v':
            if (pos == end) return Tag_0;
            if (!is_prefix_of("ar", pos, end)) return Tag_0;
            std::advance(pos, 2);
            if (pos == end) return TAG_var;
    }
    return Tag_0;
}

Tag ascii_to_Tag(const char *pos, size_t length)
{
    return ascii_to_Tag(pos, pos + length);
}
    
} // namespace
