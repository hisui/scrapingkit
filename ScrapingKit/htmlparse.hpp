//  Copyright (c) 2013 segfault.jp. All rights reserved.

#ifndef SFL_HTMLPARSE_HPP
#define SFL_HTMLPARSE_HPP

#include <algorithm>
#include "./unicode.hpp"

namespace sf
{

enum ElemType
{
	ELEM_EOF = 0,
	ELEM_COMMENT,
	ELEM_TEXT,
	ELEM_BEGIN,
	ELEM_CLOSE,
	ELEM_ERROR,
};

enum AttrType
{
	ATTR_END = 0,
	ATTR_KEY,
	ATTR_KEY_VALUE,
};

template<typename InputIterator>
class basic_htmlparser: public basic_scanner<InputIterator>
{
	typedef basic_scanner<InputIterator> base;
	using base::pos;
	using base::end;
	using base::get;
	using base::get_and_inc;
	using base::inc_and_get;
public:
	basic_htmlparser(const InputIterator &pos, const InputIterator &end)
	:base(pos, end)
	{
	}

	using typename base::pair_t;
	bool read_name(pair_t &out)
	{
		skip_whitespace();
		if (!isalpha(get())) {
			return false;
		}
		auto tmp = pos;
		pos++;
		pos = std::find_if(pos, end, [] (uint32_t c) {
			return !(isalnum(c) || c == '-');
		});
		out = std::make_pair(tmp, pos);
		return true;
	}

	bool read_char(uint32_t c)
	{
		skip_whitespace();
		if (get() == c) {
			get_and_inc();
			return true;
		}
		return false;
	}

	static bool is_whitespace(uint32_t c)
	{
		switch(c) {
		case '\n': case '\r':
		case '\t': case '\f': case ' ':
			return true;
		}
		return false;
	}

	void skip_whitespace()
	{
		while (pos != end && is_whitespace(*pos)) {
			++pos;
		}
	}

	AttrType next_attr(pair_t &key, pair_t &val)
	{
		auto save = pos;
		if (!read_name(key)) return ATTR_END;
		if (!read_char('=')) return ATTR_KEY;
		skip_whitespace();
		auto i = pos;
		auto c = get();
		pos =  c == '\''
			|| c ==  '"'
			? std::find   (++i, end, c)
			: std::find_if(pos, end, [] (uint32_t c) {
				return is_whitespace(c)
					|| c == '<'
					|| c == '>'
					;
			});
		if (pos == end) { // error & ignore
			pos = save;
			return ATTR_END;
		}
		val = std::make_pair(i, pos);
		if (*pos == c) {
			++pos;
		}
		return ATTR_KEY_VALUE;
	}

	ElemType enter_elem(pair_t &out)
	{
		auto save = pos;
		while (pos != end) {
			if (save != (pos = std::find(pos, end, '<'))) {
				out = std::make_pair(save, pos);
				return ELEM_TEXT;
			}
			++pos;
			if (read_char('/')) {
				if (!(read_name(out) && read_char('>'))) {
					continue;
				}
				return ELEM_CLOSE;
			}
			if (read_name(out)) {
				return ELEM_BEGIN;
			}
			if (read_char('!')
				&& get_and_inc() == '-'
				&& get_and_inc() == '-')
			{
				auto p = "-->";
				auto i = std::search(pos, end, p, p+3);
				if (i == end) {
					continue;
				}
				out = std::make_pair(pos, i);
				pos = i;
				std::advance(pos, 3);
				return ELEM_COMMENT;
			}
		}
		return ELEM_EOF;
	}

	ElemType leave_elem()
	{
		auto is_slashed
		     = read_char('/') ? ELEM_CLOSE: ELEM_BEGIN;
		return read_char('>') ? is_slashed: ELEM_ERROR;
	}
};

}

#endif
