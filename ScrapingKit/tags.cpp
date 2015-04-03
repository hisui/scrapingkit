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
            return pos == end ? TAG_a: Tag_0;
            switch (*pos++) {
                case 'b':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("br", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_abbr: Tag_0;
                case 'c':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ronym", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    return pos == end ? TAG_acronym: Tag_0;
                case 'd':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("dress", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    return pos == end ? TAG_address: Tag_0;
                case 'p':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("plet", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_applet: Tag_0;
                case 'r':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ea", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_area: Tag_0;
            }
            return Tag_0;
        case 'b':
            return pos == end ? TAG_b: Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("se", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_base: Tag_0;
                    if (!is_prefix_of("font", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_basefont: Tag_0;
                case 'd':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'o') return Tag_0;
                    return pos == end ? TAG_bdo: Tag_0;
                case 'i':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'g') return Tag_0;
                    return pos == end ? TAG_big: Tag_0;
                case 'l':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ockquote", pos, end)) return Tag_0;
                    std::advance(pos, 8);
                    return pos == end ? TAG_blockquote: Tag_0;
                case 'o':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("dy", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_body: Tag_0;
                case 'r':
                    return pos == end ? TAG_br: Tag_0;
                case 'u':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("tton", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_button: Tag_0;
            }
            return Tag_0;
        case 'c':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ption", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    return pos == end ? TAG_caption: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("nter", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_center: Tag_0;
                case 'i':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("te", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_cite: Tag_0;
                case 'o':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'd':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'e') return Tag_0;
                            return pos == end ? TAG_code: Tag_0;
                        case 'l':
                            return pos == end ? TAG_col: Tag_0;
                            if (!is_prefix_of("group", pos, end)) return Tag_0;
                            std::advance(pos, 5);
                            return pos == end ? TAG_colgroup: Tag_0;
                    }
                    return Tag_0;
            }
            return Tag_0;
        case 'd':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'd':
                    return pos == end ? TAG_dd: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'l') return Tag_0;
                    return pos == end ? TAG_del: Tag_0;
                case 'f':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'n') return Tag_0;
                    return pos == end ? TAG_dfn: Tag_0;
                case 'i':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'r':
                            return pos == end ? TAG_dir: Tag_0;
                        case 'v':
                            return pos == end ? TAG_div: Tag_0;
                    }
                    return Tag_0;
                case 'l':
                    return pos == end ? TAG_dl: Tag_0;
                case 't':
                    return pos == end ? TAG_dt: Tag_0;
            }
            return Tag_0;
        case 'e':
            if (pos == end) return Tag_0;
            if (*pos++ != 'm') return Tag_0;
            return pos == end ? TAG_em: Tag_0;
        case 'f':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'i':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("eldset", pos, end)) return Tag_0;
                    std::advance(pos, 6);
                    return pos == end ? TAG_fieldset: Tag_0;
                case 'o':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'n':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 't') return Tag_0;
                            return pos == end ? TAG_font: Tag_0;
                        case 'r':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'm') return Tag_0;
                            return pos == end ? TAG_form: Tag_0;
                    }
                    return Tag_0;
                case 'r':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ame", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_frame: Tag_0;
                    if (!is_prefix_of("set", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_frameset: Tag_0;
            }
            return Tag_0;
        case 'h':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case '1':
                    return pos == end ? TAG_h1: Tag_0;
                case '2':
                    return pos == end ? TAG_h2: Tag_0;
                case '3':
                    return pos == end ? TAG_h3: Tag_0;
                case '4':
                    return pos == end ? TAG_h4: Tag_0;
                case '5':
                    return pos == end ? TAG_h5: Tag_0;
                case '6':
                    return pos == end ? TAG_h6: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ad", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_head: Tag_0;
                case 'r':
                    return pos == end ? TAG_hr: Tag_0;
                case 't':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ml", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_html: Tag_0;
            }
            return Tag_0;
        case 'i':
            return pos == end ? TAG_i: Tag_0;
            switch (*pos++) {
                case 'f':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("rame", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_iframe: Tag_0;
                case 'm':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'g') return Tag_0;
                    return pos == end ? TAG_img: Tag_0;
                case 'n':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'p':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("ut", pos, end)) return Tag_0;
                            std::advance(pos, 2);
                            return pos == end ? TAG_input: Tag_0;
                        case 's':
                            return pos == end ? TAG_ins: Tag_0;
                    }
                    return Tag_0;
                case 's':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("index", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    return pos == end ? TAG_isindex: Tag_0;
            }
            return Tag_0;
        case 'k':
            if (pos == end) return Tag_0;
            if (!is_prefix_of("bd", pos, end)) return Tag_0;
            std::advance(pos, 2);
            return pos == end ? TAG_kbd: Tag_0;
        case 'l':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("bel", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_label: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("gend", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_legend: Tag_0;
                case 'i':
                    return pos == end ? TAG_li: Tag_0;
                    if (!is_prefix_of("nk", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_link: Tag_0;
            }
            return Tag_0;
        case 'm':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'p') return Tag_0;
                    return pos == end ? TAG_map: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'n':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'u') return Tag_0;
                            return pos == end ? TAG_menu: Tag_0;
                        case 't':
                            if (pos == end) return Tag_0;
                            if (*pos++ != 'a') return Tag_0;
                            return pos == end ? TAG_meta: Tag_0;
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
                    return pos == end ? TAG_noframes: Tag_0;
                case 's':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("cript", pos, end)) return Tag_0;
                    std::advance(pos, 5);
                    return pos == end ? TAG_noscript: Tag_0;
            }
            return Tag_0;
        case 'o':
            if (pos == end) return Tag_0;
            switch (*pos++) {
                case 'b':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ject", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_object: Tag_0;
                case 'l':
                    return pos == end ? TAG_ol: Tag_0;
                case 'p':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 't') return Tag_0;
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'g':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("roup", pos, end)) return Tag_0;
                            std::advance(pos, 4);
                            return pos == end ? TAG_optgroup: Tag_0;
                        case 'i':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("on", pos, end)) return Tag_0;
                            std::advance(pos, 2);
                            return pos == end ? TAG_option: Tag_0;
                    }
                    return Tag_0;
            }
            return Tag_0;
        case 'p':
            return pos == end ? TAG_p: Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ram", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_param: Tag_0;
                case 'r':
                    if (pos == end) return Tag_0;
                    if (*pos++ != 'e') return Tag_0;
                    return pos == end ? TAG_pre: Tag_0;
            }
            return Tag_0;
        case 'q':
            return pos == end ? TAG_q: Tag_0;
        case 's':
            return pos == end ? TAG_s: Tag_0;
            switch (*pos++) {
                case 'a':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("mp", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_samp: Tag_0;
                case 'c':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ript", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_script: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("lect", pos, end)) return Tag_0;
                    std::advance(pos, 4);
                    return pos == end ? TAG_select: Tag_0;
                case 'm':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("all", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_small: Tag_0;
                case 'p':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("an", pos, end)) return Tag_0;
                    std::advance(pos, 2);
                    return pos == end ? TAG_span: Tag_0;
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
                                    return pos == end ? TAG_strike: Tag_0;
                                case 'o':
                                    if (pos == end) return Tag_0;
                                    if (!is_prefix_of("ng", pos, end)) return Tag_0;
                                    std::advance(pos, 2);
                                    return pos == end ? TAG_strong: Tag_0;
                            }
                            return Tag_0;
                        case 'y':
                            if (pos == end) return Tag_0;
                            if (!is_prefix_of("le", pos, end)) return Tag_0;
                            std::advance(pos, 2);
                            return pos == end ? TAG_style: Tag_0;
                    }
                    return Tag_0;
                case 'u':
                    if (pos == end) return Tag_0;
                    switch (*pos++) {
                        case 'b':
                            return pos == end ? TAG_sub: Tag_0;
                        case 'p':
                            return pos == end ? TAG_sup: Tag_0;
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
                    return pos == end ? TAG_table: Tag_0;
                case 'b':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("ody", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_tbody: Tag_0;
                case 'd':
                    return pos == end ? TAG_td: Tag_0;
                case 'e':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("xtarea", pos, end)) return Tag_0;
                    std::advance(pos, 6);
                    return pos == end ? TAG_textarea: Tag_0;
                case 'f':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("oot", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_tfoot: Tag_0;
                case 'h':
                    return pos == end ? TAG_th: Tag_0;
                    if (!is_prefix_of("ead", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_thead: Tag_0;
                case 'i':
                    if (pos == end) return Tag_0;
                    if (!is_prefix_of("tle", pos, end)) return Tag_0;
                    std::advance(pos, 3);
                    return pos == end ? TAG_title: Tag_0;
                case 'r':
                    return pos == end ? TAG_tr: Tag_0;
                case 't':
                    return pos == end ? TAG_tt: Tag_0;
            }
            return Tag_0;
        case 'u':
            return pos == end ? TAG_u: Tag_0;
            if (*pos++ != 'l') return Tag_0;
            return pos == end ? TAG_ul: Tag_0;
        case 'v':
            if (pos == end) return Tag_0;
            if (!is_prefix_of("ar", pos, end)) return Tag_0;
            std::advance(pos, 2);
            return pos == end ? TAG_var: Tag_0;
    }
    return Tag_0;
}
    
Tag ascii_to_Tag(const char *pos, size_t length)
{
    return ascii_to_Tag(pos, pos + length);
}
    
} // namespace
