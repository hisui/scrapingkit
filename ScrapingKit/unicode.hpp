//  Copyright (c) 2013 segfault.jp. All rights reserved.

#ifndef SFL_UNICODE_HPP
#define SFL_UNICODE_HPP

#include <iterator>
#include <tuple>
#include <type_traits>

namespace sf {
namespace { extern void *enabler; }
    
typedef uint32_t codepoint;

template<typename InputIterator>
struct utf32_decoder
		: public std::iterator<std::input_iterator_tag, uint32_t>
{
	utf32_decoder(const InputIterator &base)
	:base(base)
	{
	}

	uint32_t operator*() const { return uint32_t(*base); }

	utf32_decoder &operator++()
	{
		++base;
		return *this;
	}

	bool operator!=(const utf32_decoder &rhs) const
	{
		return base != rhs.base;
	}

	InputIterator base;
};

    
template<typename InputIterator>
struct utf16_decoder
: public std::iterator<std::input_iterator_tag, uint32_t>
{
    utf16_decoder(const InputIterator &base)
    :base(base)
    {
    }
        
    uint32_t operator*() const
    {
        uint16_t c = *base;
        return is_hi_surrogate(c)
            ? c << 10 | (base[1] & 0x3ff) // TODO ここ、オフセットをたさないとダメ
            : c ;
    }

    utf16_decoder &operator++()
    {
        base += is_hi_surrogate(*base) ? 2: 1;
        return *this;
    }
        
    bool operator!=(const utf16_decoder &rhs) const
    {
        return base != rhs.base;
    }

    inline static bool is_hi_surrogate(uint16_t c) { return (c & 0xfc00) == 0xd800; }
    inline static bool is_lo_surrogate(uint16_t c) { return (c & 0xfc00) == 0xdc00; }

    InputIterator base;
};
    
    
template<typename InputIterator>
struct utf8_decoder
: public std::iterator<std::input_iterator_tag, uint32_t>
{
    utf8_decoder(const InputIterator &base)
    :base(base)
    {
    }
    
    inline static int count_bytes(uint8_t c)
    {
        return
        ((c >> 6) + 1 >> 2) +
        ((c >> 5) + 1 >> 3) +
        ((c >> 4) + 1 >> 4) +
        ((c >> 3) + 1 >> 5) +
        ((c >> 2) + 1 >> 6) ;
    }
        
    uint32_t operator*() const
    {
        uint8_t c = *base;
        if (!(c & 0x80)) return c;
        uint32_t n = count_bytes(c);
        uint32_t u = 0;
        switch (n) {
        case 5: u |= (base[5] & 0x3f);
        case 4: u |= (base[4] & 0x3f) << (n - 4) * 6;
        case 3: u |= (base[3] & 0x3f) << (n - 3) * 6;
        case 2: u |= (base[2] & 0x3f) << (n - 2) * 6;
        case 1: u |= (base[1] & 0x3f) << (n - 1) * 6;
        }
        return u | (c & (0x3fu >> n)) << n * 6;
    }
        
    utf8_decoder &operator++()
    {
        base += 1 + count_bytes(*base);
        return *this;
    }
        
    bool operator!=(const utf8_decoder &rhs) const
    {
        return base != rhs.base;
    }
        
    InputIterator base;
};

template<typename V, typename I>
using iter_of = std::is_same<V,typename std::iterator_traits<I>::value_type>;

template<typename II, typename std::enable_if<iter_of<uint32_t,II>::value>::type *& = enabler>
utf32_decoder<II> make_unicode_iterator(const II &i)
{
	return utf32_decoder<II>(i);
}
    
template<typename II, typename std::enable_if<iter_of<uint16_t,II>::value>::type *& = enabler>
utf16_decoder<II> make_unicode_iterator(const II &i)
{
    return utf16_decoder<II>(i);
}
    
template<typename II, typename std::enable_if<iter_of<char,II>::value>::type *& = enabler>
utf8_decoder<II> make_unicode_iterator(const II &i)
{
    return utf8_decoder<II>(i);
}

template<typename InputIterator, uint32_t Eof=uint32_t(-1)>
class basic_scanner
{
public:
	basic_scanner(const InputIterator &pos, const InputIterator &end)
	:pos(pos)
	,end(end)
	{
	}

	typedef std::pair<InputIterator,InputIterator> pair_t;
	enum :uint32_t { eof = Eof };
	uint32_t get        () { return pos == end ? eof: uint32_t(*pos  ); }
	uint32_t get_and_inc() { return pos == end ? eof: uint32_t(*pos++); }
	uint32_t inc_and_get() {
		if(  pos == end) return eof;
		if(++pos == end) return eof;
		return *pos;
	}

	InputIterator pos;
	InputIterator end;
};

} // namespace

#endif
