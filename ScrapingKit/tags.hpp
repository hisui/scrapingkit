#ifndef ScrapingKit_tags_hpp
#define ScrapingKit_tags_hpp

#include <stdlib.h>

namespace sf {

enum Tag: uint32_t
{
    Tag_0 = 0,
    TAG_a = 1,
    TAG_abbr = 2,
    TAG_acronym = 3,
    TAG_address = 4,
    TAG_applet = 5,
    TAG_area = 6,
    TAG_b = 7,
    TAG_base = 8,
    TAG_basefont = 9,
    TAG_bdo = 10,
    TAG_big = 11,
    TAG_blockquote = 12,
    TAG_body = 13,
    TAG_br = 14,
    TAG_button = 15,
    TAG_caption = 16,
    TAG_center = 17,
    TAG_cite = 18,
    TAG_code = 19,
    TAG_col = 20,
    TAG_colgroup = 21,
    TAG_dd = 22,
    TAG_del = 23,
    TAG_dfn = 24,
    TAG_dir = 25,
    TAG_div = 26,
    TAG_dl = 27,
    TAG_dt = 28,
    TAG_em = 29,
    TAG_fieldset = 30,
    TAG_font = 31,
    TAG_form = 32,
    TAG_frame = 33,
    TAG_frameset = 34,
    TAG_h1 = 35,
    TAG_h2 = 36,
    TAG_h3 = 37,
    TAG_h4 = 38,
    TAG_h5 = 39,
    TAG_h6 = 40,
    TAG_head = 41,
    TAG_hr = 42,
    TAG_html = 43,
    TAG_i = 44,
    TAG_iframe = 45,
    TAG_img = 46,
    TAG_input = 47,
    TAG_ins = 48,
    TAG_isindex = 49,
    TAG_kbd = 50,
    TAG_label = 51,
    TAG_legend = 52,
    TAG_li = 53,
    TAG_link = 54,
    TAG_map = 55,
    TAG_menu = 56,
    TAG_meta = 57,
    TAG_noframes = 58,
    TAG_noscript = 59,
    TAG_object = 60,
    TAG_ol = 61,
    TAG_optgroup = 62,
    TAG_option = 63,
    TAG_p = 64,
    TAG_param = 65,
    TAG_pre = 66,
    TAG_q = 67,
    TAG_s = 68,
    TAG_samp = 69,
    TAG_script = 70,
    TAG_select = 71,
    TAG_small = 72,
    TAG_span = 73,
    TAG_strike = 74,
    TAG_strong = 75,
    TAG_style = 76,
    TAG_sub = 77,
    TAG_sup = 78,
    TAG_table = 79,
    TAG_tbody = 80,
    TAG_td = 81,
    TAG_textarea = 82,
    TAG_tfoot = 83,
    TAG_th = 84,
    TAG_thead = 85,
    TAG_title = 86,
    TAG_tr = 87,
    TAG_tt = 88,
    TAG_u = 89,
    TAG_ul = 90,
    TAG_var = 91,
};
    
extern Tag ascii_to_Tag(const char *pos, size_t length);

} // namespace

#endif
