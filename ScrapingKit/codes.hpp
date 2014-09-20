template <size_t N, typename InputIterator> bool is_prefix_of(const char (&src)[N], InputIterator pos, InputIterator end)
{
  for (int i = 0; i < N-1; ++i) {
    if (pos == end || *pos++ != src[i]) return false;
  }
  return true;
}

enum code: uint32_t
{
	Code_0 = 0,
	CODE_AElig = 198,
	CODE_Aacute = 193,
	CODE_Acirc = 194,
	CODE_Agrave = 192,
	CODE_Alpha = 913,
	CODE_Aring = 197,
	CODE_Atilde = 195,
	CODE_Auml = 196,
	CODE_Beta = 914,
	CODE_Ccedil = 199,
	CODE_Chi = 935,
	CODE_Dagger = 8225,
	CODE_Delta = 916,
	CODE_ETH = 208,
	CODE_Eacute = 201,
	CODE_Ecirc = 202,
	CODE_Egrave = 200,
	CODE_Epsilon = 917,
	CODE_Eta = 919,
	CODE_Euml = 203,
	CODE_Gamma = 915,
	CODE_Iacute = 205,
	CODE_Icirc = 206,
	CODE_Igrave = 204,
	CODE_Iota = 921,
	CODE_Iuml = 207,
	CODE_Kappa = 922,
	CODE_Lambda = 923,
	CODE_Mu = 924,
	CODE_Ntilde = 209,
	CODE_Nu = 925,
	CODE_OElig = 338,
	CODE_Oacute = 211,
	CODE_Ocirc = 212,
	CODE_Ograve = 210,
	CODE_Omega = 937,
	CODE_Omicron = 927,
	CODE_Oslash = 216,
	CODE_Otilde = 213,
	CODE_Ouml = 214,
	CODE_Phi = 934,
	CODE_Pi = 928,
	CODE_Prime = 8243,
	CODE_Psi = 936,
	CODE_Rho = 929,
	CODE_Scaron = 352,
	CODE_Sigma = 931,
	CODE_THORN = 222,
	CODE_Tau = 932,
	CODE_Theta = 920,
	CODE_Uacute = 218,
	CODE_Ucirc = 219,
	CODE_Ugrave = 217,
	CODE_Upsilon = 933,
	CODE_Uuml = 220,
	CODE_Xi = 926,
	CODE_Yacute = 221,
	CODE_Yuml = 376,
	CODE_Zeta = 918,
	CODE_aacute = 225,
	CODE_acirc = 226,
	CODE_acute = 180,
	CODE_aelig = 230,
	CODE_agrave = 224,
	CODE_alefsym = 8501,
	CODE_alpha = 945,
	CODE_amp = 38,
	CODE_and = 8743,
	CODE_ang = 8736,
	CODE_aring = 229,
	CODE_asymp = 8776,
	CODE_atilde = 227,
	CODE_auml = 228,
	CODE_bdquo = 8222,
	CODE_beta = 946,
	CODE_brvbar = 166,
	CODE_bull = 8226,
	CODE_cap = 8745,
	CODE_ccedil = 231,
	CODE_cedil = 184,
	CODE_cent = 162,
	CODE_chi = 967,
	CODE_circ = 710,
	CODE_clubs = 9827,
	CODE_cong = 8773,
	CODE_copy = 169,
	CODE_crarr = 8629,
	CODE_cup = 8746,
	CODE_curren = 164,
	CODE_dArr = 8659,
	CODE_dagger = 8224,
	CODE_darr = 8595,
	CODE_deg = 176,
	CODE_delta = 948,
	CODE_diams = 9830,
	CODE_divide = 247,
	CODE_eacute = 233,
	CODE_ecirc = 234,
	CODE_egrave = 232,
	CODE_empty = 8709,
	CODE_emsp = 8195,
	CODE_ensp = 8194,
	CODE_epsilon = 949,
	CODE_equiv = 8801,
	CODE_eta = 951,
	CODE_eth = 240,
	CODE_euml = 235,
	CODE_exist = 8707,
	CODE_fnof = 402,
	CODE_forall = 8704,
	CODE_frac12 = 189,
	CODE_frac14 = 188,
	CODE_frac34 = 190,
	CODE_frasl = 8260,
	CODE_gamma = 947,
	CODE_ge = 8805,
	CODE_gt = 62,
	CODE_hArr = 8660,
	CODE_harr = 8596,
	CODE_hearts = 9829,
	CODE_hellip = 8230,
	CODE_iacute = 237,
	CODE_icirc = 238,
	CODE_iexcl = 161,
	CODE_igrave = 236,
	CODE_image = 8465,
	CODE_infin = 8734,
	CODE_int = 8747,
	CODE_iota = 953,
	CODE_iquest = 191,
	CODE_isin = 8712,
	CODE_iuml = 239,
	CODE_kappa = 954,
	CODE_lArr = 8656,
	CODE_lambda = 955,
	CODE_lang = 9001,
	CODE_laquo = 171,
	CODE_larr = 8592,
	CODE_lceil = 8968,
	CODE_ldquo = 8220,
	CODE_le = 8804,
	CODE_lfloor = 8970,
	CODE_lowast = 8727,
	CODE_loz = 9674,
	CODE_lrm = 8206,
	CODE_lsaquo = 8249,
	CODE_lsquo = 8216,
	CODE_lt = 60,
	CODE_macr = 175,
	CODE_mdash = 8212,
	CODE_micro = 181,
	CODE_middot = 183,
	CODE_minus = 8722,
	CODE_mu = 956,
	CODE_nabla = 8711,
	CODE_nbsp = 160,
	CODE_ndash = 8211,
	CODE_ne = 8800,
	CODE_ni = 8715,
	CODE_not = 172,
	CODE_notin = 8713,
	CODE_nsub = 8836,
	CODE_ntilde = 241,
	CODE_nu = 957,
	CODE_oacute = 243,
	CODE_ocirc = 244,
	CODE_oelig = 339,
	CODE_ograve = 242,
	CODE_oline = 8254,
	CODE_omega = 969,
	CODE_omicron = 959,
	CODE_oplus = 8853,
	CODE_or = 8744,
	CODE_ordf = 170,
	CODE_ordm = 186,
	CODE_oslash = 248,
	CODE_otilde = 245,
	CODE_otimes = 8855,
	CODE_ouml = 246,
	CODE_para = 182,
	CODE_part = 8706,
	CODE_permil = 8240,
	CODE_perp = 8869,
	CODE_phi = 966,
	CODE_pi = 960,
	CODE_piv = 982,
	CODE_plusmn = 177,
	CODE_pound = 163,
	CODE_prime = 8242,
	CODE_prod = 8719,
	CODE_prop = 8733,
	CODE_psi = 968,
	CODE_quot = 34,
	CODE_rArr = 8658,
	CODE_radic = 8730,
	CODE_rang = 9002,
	CODE_raquo = 187,
	CODE_rarr = 8594,
	CODE_rceil = 8969,
	CODE_rdquo = 8221,
	CODE_real = 8476,
	CODE_reg = 174,
	CODE_rfloor = 8971,
	CODE_rho = 961,
	CODE_rlm = 8207,
	CODE_rsquo = 8217,
	CODE_sbquo = 8218,
	CODE_scaron = 353,
	CODE_sdot = 8901,
	CODE_sect = 167,
	CODE_shy = 173,
	CODE_sigma = 963,
	CODE_sigmaf = 962,
	CODE_sim = 8764,
	CODE_spades = 9824,
	CODE_sub = 8834,
	CODE_sube = 8838,
	CODE_sum = 8721,
	CODE_sup = 8835,
	CODE_sup1 = 185,
	CODE_sup2 = 178,
	CODE_sup3 = 179,
	CODE_supe = 8839,
	CODE_szlig = 223,
	CODE_tau = 964,
	CODE_there4 = 8756,
	CODE_theta = 952,
	CODE_thetasym = 977,
	CODE_thinsp = 8201,
	CODE_thorn = 254,
	CODE_tilde = 732,
	CODE_times = 215,
	CODE_trade = 8482,
	CODE_uArr = 8657,
	CODE_uacute = 250,
	CODE_uarr = 8593,
	CODE_ucirc = 251,
	CODE_ugrave = 249,
	CODE_uml = 168,
	CODE_upsih = 978,
	CODE_upsilon = 965,
	CODE_uuml = 252,
	CODE_weierp = 8472,
	CODE_xi = 958,
	CODE_yacute = 253,
	CODE_yen = 165,
	CODE_yuml = 255,
	CODE_zeta = 950,
	CODE_zwj = 8205,
	CODE_zwnj = 8204,
};

template <typename InputIterator>
code ascii_to_code(InputIterator pos, InputIterator end)
{
	if (pos == end) return Code_0;
	switch (*pos++) {
	case 'A':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'E':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lig", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_AElig: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Aacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Acirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Agrave: Code_0;
		case 'l':
			if (pos == end) return Code_0;
			if (!is_prefix_of("pha", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Alpha: Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ing", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Aring: Code_0;
		case 't':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ilde", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Atilde: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Auml: Code_0;
		}
		return Code_0;
	case 'B':
		if (pos == end) return Code_0;
		if (!is_prefix_of("eta", pos, end)) return Code_0;
		std::advance(pos, 3);
		return pos == end ? CODE_Beta: Code_0;
	case 'C':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("edil", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Ccedil: Code_0;
		case 'h':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			return pos == end ? CODE_Chi: Code_0;
		}
		return Code_0;
	case 'D':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("gger", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Dagger: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lta", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Delta: Code_0;
		}
		return Code_0;
	case 'E':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'T':
			if (pos == end) return Code_0;
			if (*pos++ != 'H') return Code_0;
			return pos == end ? CODE_ETH: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Eacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Ecirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Egrave: Code_0;
		case 'p':
			if (pos == end) return Code_0;
			if (!is_prefix_of("silon", pos, end)) return Code_0;
			std::advance(pos, 5);
			return pos == end ? CODE_Epsilon: Code_0;
		case 't':
			if (pos == end) return Code_0;
			if (*pos++ != 'a') return Code_0;
			return pos == end ? CODE_Eta: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Euml: Code_0;
		}
		return Code_0;
	case 'G':
		if (pos == end) return Code_0;
		if (!is_prefix_of("amma", pos, end)) return Code_0;
		std::advance(pos, 4);
		return pos == end ? CODE_Gamma: Code_0;
	case 'I':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Iacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Icirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Igrave: Code_0;
		case 'o':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ta", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Iota: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Iuml: Code_0;
		}
		return Code_0;
	case 'K':
		if (pos == end) return Code_0;
		if (!is_prefix_of("appa", pos, end)) return Code_0;
		std::advance(pos, 4);
		return pos == end ? CODE_Kappa: Code_0;
	case 'L':
		if (pos == end) return Code_0;
		if (!is_prefix_of("ambda", pos, end)) return Code_0;
		std::advance(pos, 5);
		return pos == end ? CODE_Lambda: Code_0;
	case 'M':
		if (pos == end) return Code_0;
		if (*pos++ != 'u') return Code_0;
		return pos == end ? CODE_Mu: Code_0;
	case 'N':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 't':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ilde", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Ntilde: Code_0;
		case 'u':
			return pos == end ? CODE_Nu: Code_0;
		}
		return Code_0;
	case 'O':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'E':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lig", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_OElig: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Oacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Ocirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Ograve: Code_0;
		case 'm':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'e':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ga", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_Omega: Code_0;
			case 'i':
				if (pos == end) return Code_0;
				if (!is_prefix_of("cron", pos, end)) return Code_0;
				std::advance(pos, 4);
				return pos == end ? CODE_Omicron: Code_0;
			}
			return Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lash", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Oslash: Code_0;
		case 't':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ilde", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Otilde: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Ouml: Code_0;
		}
		return Code_0;
	case 'P':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'h':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			return pos == end ? CODE_Phi: Code_0;
		case 'i':
			return pos == end ? CODE_Pi: Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ime", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Prime: Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			return pos == end ? CODE_Psi: Code_0;
		}
		return Code_0;
	case 'R':
		if (pos == end) return Code_0;
		if (!is_prefix_of("ho", pos, end)) return Code_0;
		std::advance(pos, 2);
		return pos == end ? CODE_Rho: Code_0;
	case 'S':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("aron", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Scaron: Code_0;
		case 'i':
			if (pos == end) return Code_0;
			if (!is_prefix_of("gma", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Sigma: Code_0;
		}
		return Code_0;
	case 'T':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'H':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ORN", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_THORN: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			if (*pos++ != 'u') return Code_0;
			return pos == end ? CODE_Tau: Code_0;
		case 'h':
			if (pos == end) return Code_0;
			if (!is_prefix_of("eta", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Theta: Code_0;
		}
		return Code_0;
	case 'U':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Uacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_Ucirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Ugrave: Code_0;
		case 'p':
			if (pos == end) return Code_0;
			if (!is_prefix_of("silon", pos, end)) return Code_0;
			std::advance(pos, 5);
			return pos == end ? CODE_Upsilon: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Uuml: Code_0;
		}
		return Code_0;
	case 'X':
		if (pos == end) return Code_0;
		if (*pos++ != 'i') return Code_0;
		return pos == end ? CODE_Xi: Code_0;
	case 'Y':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_Yacute: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_Yuml: Code_0;
		}
		return Code_0;
	case 'Z':
		if (pos == end) return Code_0;
		if (!is_prefix_of("eta", pos, end)) return Code_0;
		std::advance(pos, 3);
		return pos == end ? CODE_Zeta: Code_0;
	case 'a':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_aacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'i':
				if (pos == end) return Code_0;
				if (!is_prefix_of("rc", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_acirc: Code_0;
			case 'u':
				if (pos == end) return Code_0;
				if (!is_prefix_of("te", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_acute: Code_0;
			}
			return Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lig", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_aelig: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_agrave: Code_0;
		case 'l':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'e':
				if (pos == end) return Code_0;
				if (!is_prefix_of("fsym", pos, end)) return Code_0;
				std::advance(pos, 4);
				return pos == end ? CODE_alefsym: Code_0;
			case 'p':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ha", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_alpha: Code_0;
			}
			return Code_0;
		case 'm':
			if (pos == end) return Code_0;
			if (*pos++ != 'p') return Code_0;
			return pos == end ? CODE_amp: Code_0;
		case 'n':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'd':
				return pos == end ? CODE_and: Code_0;
			case 'g':
				return pos == end ? CODE_ang: Code_0;
			}
			return Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ing", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_aring: Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ymp", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_asymp: Code_0;
		case 't':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ilde", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_atilde: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_auml: Code_0;
		}
		return Code_0;
	case 'b':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'd':
			if (pos == end) return Code_0;
			if (!is_prefix_of("quo", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_bdquo: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ta", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_beta: Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (!is_prefix_of("vbar", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_brvbar: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ll", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_bull: Code_0;
		}
		return Code_0;
	case 'c':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (*pos++ != 'p') return Code_0;
			return pos == end ? CODE_cap: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("edil", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_ccedil: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'd':
				if (pos == end) return Code_0;
				if (!is_prefix_of("il", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_cedil: Code_0;
			case 'n':
				if (pos == end) return Code_0;
				if (*pos++ != 't') return Code_0;
				return pos == end ? CODE_cent: Code_0;
			}
			return Code_0;
		case 'h':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			return pos == end ? CODE_chi: Code_0;
		case 'i':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rc", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_circ: Code_0;
		case 'l':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ubs", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_clubs: Code_0;
		case 'o':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'n':
				if (pos == end) return Code_0;
				if (*pos++ != 'g') return Code_0;
				return pos == end ? CODE_cong: Code_0;
			case 'p':
				if (pos == end) return Code_0;
				if (*pos++ != 'y') return Code_0;
				return pos == end ? CODE_copy: Code_0;
			}
			return Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (!is_prefix_of("arr", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_crarr: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'p':
				return pos == end ? CODE_cup: Code_0;
			case 'r':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ren", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_curren: Code_0;
			}
			return Code_0;
		}
		return Code_0;
	case 'd':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'A':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_dArr: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'g':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ger", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_dagger: Code_0;
			case 'r':
				if (pos == end) return Code_0;
				if (*pos++ != 'r') return Code_0;
				return pos == end ? CODE_darr: Code_0;
			}
			return Code_0;
		case 'e':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'g':
				return pos == end ? CODE_deg: Code_0;
			case 'l':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ta", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_delta: Code_0;
			}
			return Code_0;
		case 'i':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'a':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ms", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_diams: Code_0;
			case 'v':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ide", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_divide: Code_0;
			}
			return Code_0;
		}
		return Code_0;
	case 'e':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_eacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_ecirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_egrave: Code_0;
		case 'm':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'p':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ty", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_empty: Code_0;
			case 's':
				if (pos == end) return Code_0;
				if (*pos++ != 'p') return Code_0;
				return pos == end ? CODE_emsp: Code_0;
			}
			return Code_0;
		case 'n':
			if (pos == end) return Code_0;
			if (!is_prefix_of("sp", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_ensp: Code_0;
		case 'p':
			if (pos == end) return Code_0;
			if (!is_prefix_of("silon", pos, end)) return Code_0;
			std::advance(pos, 5);
			return pos == end ? CODE_epsilon: Code_0;
		case 'q':
			if (pos == end) return Code_0;
			if (!is_prefix_of("uiv", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_equiv: Code_0;
		case 't':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'a':
				return pos == end ? CODE_eta: Code_0;
			case 'h':
				return pos == end ? CODE_eth: Code_0;
			}
			return Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_euml: Code_0;
		case 'x':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ist", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_exist: Code_0;
		}
		return Code_0;
	case 'f':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'n':
			if (pos == end) return Code_0;
			if (!is_prefix_of("of", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_fnof: Code_0;
		case 'o':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rall", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_forall: Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (*pos++ != 'a') return Code_0;
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'c':
				if (pos == end) return Code_0;
				switch (*pos++) {
				case '1':
					if (pos == end) return Code_0;
					switch (*pos++) {
					case '2':
						return pos == end ? CODE_frac12: Code_0;
					case '4':
						return pos == end ? CODE_frac14: Code_0;
					}
					return Code_0;
				case '3':
					if (pos == end) return Code_0;
					if (*pos++ != '4') return Code_0;
					return pos == end ? CODE_frac34: Code_0;
				}
				return Code_0;
			case 's':
				if (pos == end) return Code_0;
				if (*pos++ != 'l') return Code_0;
				return pos == end ? CODE_frasl: Code_0;
			}
			return Code_0;
		}
		return Code_0;
	case 'g':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("mma", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_gamma: Code_0;
		case 'e':
			return pos == end ? CODE_ge: Code_0;
		case 't':
			return pos == end ? CODE_gt: Code_0;
		}
		return Code_0;
	case 'h':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'A':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_hArr: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_harr: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'a':
				if (pos == end) return Code_0;
				if (!is_prefix_of("rts", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_hearts: Code_0;
			case 'l':
				if (pos == end) return Code_0;
				if (!is_prefix_of("lip", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_hellip: Code_0;
			}
			return Code_0;
		}
		return Code_0;
	case 'i':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_iacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_icirc: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("xcl", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_iexcl: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_igrave: Code_0;
		case 'm':
			if (pos == end) return Code_0;
			if (!is_prefix_of("age", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_image: Code_0;
		case 'n':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'f':
				if (pos == end) return Code_0;
				if (!is_prefix_of("in", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_infin: Code_0;
			case 't':
				return pos == end ? CODE_int: Code_0;
			}
			return Code_0;
		case 'o':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ta", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_iota: Code_0;
		case 'q':
			if (pos == end) return Code_0;
			if (!is_prefix_of("uest", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_iquest: Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (!is_prefix_of("in", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_isin: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_iuml: Code_0;
		}
		return Code_0;
	case 'k':
		if (pos == end) return Code_0;
		if (!is_prefix_of("appa", pos, end)) return Code_0;
		std::advance(pos, 4);
		return pos == end ? CODE_kappa: Code_0;
	case 'l':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'A':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_lArr: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'm':
				if (pos == end) return Code_0;
				if (!is_prefix_of("bda", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_lambda: Code_0;
			case 'n':
				if (pos == end) return Code_0;
				if (*pos++ != 'g') return Code_0;
				return pos == end ? CODE_lang: Code_0;
			case 'q':
				if (pos == end) return Code_0;
				if (!is_prefix_of("uo", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_laquo: Code_0;
			case 'r':
				if (pos == end) return Code_0;
				if (*pos++ != 'r') return Code_0;
				return pos == end ? CODE_larr: Code_0;
			}
			return Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("eil", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_lceil: Code_0;
		case 'd':
			if (pos == end) return Code_0;
			if (!is_prefix_of("quo", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_ldquo: Code_0;
		case 'e':
			return pos == end ? CODE_le: Code_0;
		case 'f':
			if (pos == end) return Code_0;
			if (!is_prefix_of("loor", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_lfloor: Code_0;
		case 'o':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'w':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ast", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_lowast: Code_0;
			case 'z':
				return pos == end ? CODE_loz: Code_0;
			}
			return Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (*pos++ != 'm') return Code_0;
			return pos == end ? CODE_lrm: Code_0;
		case 's':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'a':
				if (pos == end) return Code_0;
				if (!is_prefix_of("quo", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_lsaquo: Code_0;
			case 'q':
				if (pos == end) return Code_0;
				if (!is_prefix_of("uo", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_lsquo: Code_0;
			}
			return Code_0;
		case 't':
			return pos == end ? CODE_lt: Code_0;
		}
		return Code_0;
	case 'm':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_macr: Code_0;
		case 'd':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ash", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_mdash: Code_0;
		case 'i':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'c':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ro", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_micro: Code_0;
			case 'd':
				if (pos == end) return Code_0;
				if (!is_prefix_of("dot", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_middot: Code_0;
			case 'n':
				if (pos == end) return Code_0;
				if (!is_prefix_of("us", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_minus: Code_0;
			}
			return Code_0;
		case 'u':
			return pos == end ? CODE_mu: Code_0;
		}
		return Code_0;
	case 'n':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("bla", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_nabla: Code_0;
		case 'b':
			if (pos == end) return Code_0;
			if (!is_prefix_of("sp", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_nbsp: Code_0;
		case 'd':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ash", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_ndash: Code_0;
		case 'e':
			return pos == end ? CODE_ne: Code_0;
		case 'i':
			return pos == end ? CODE_ni: Code_0;
		case 'o':
			if (pos == end) return Code_0;
			if (*pos++ != 't') return Code_0;
			return pos == end ? CODE_not: Code_0;
			if (!is_prefix_of("in", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_notin: Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ub", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_nsub: Code_0;
		case 't':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ilde", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_ntilde: Code_0;
		case 'u':
			return pos == end ? CODE_nu: Code_0;
		}
		return Code_0;
	case 'o':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_oacute: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_ocirc: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lig", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_oelig: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_ograve: Code_0;
		case 'l':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ine", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_oline: Code_0;
		case 'm':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'e':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ga", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_omega: Code_0;
			case 'i':
				if (pos == end) return Code_0;
				if (!is_prefix_of("cron", pos, end)) return Code_0;
				std::advance(pos, 4);
				return pos == end ? CODE_omicron: Code_0;
			}
			return Code_0;
		case 'p':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lus", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_oplus: Code_0;
		case 'r':
			return pos == end ? CODE_or: Code_0;
			if (*pos++ != 'd') return Code_0;
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'f':
				return pos == end ? CODE_ordf: Code_0;
			case 'm':
				return pos == end ? CODE_ordm: Code_0;
			}
			return Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lash", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_oslash: Code_0;
		case 't':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'l':
				if (pos == end) return Code_0;
				if (!is_prefix_of("de", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_otilde: Code_0;
			case 'm':
				if (pos == end) return Code_0;
				if (!is_prefix_of("es", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_otimes: Code_0;
			}
			return Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_ouml: Code_0;
		}
		return Code_0;
	case 'p':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (*pos++ != 'r') return Code_0;
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'a':
				return pos == end ? CODE_para: Code_0;
			case 't':
				return pos == end ? CODE_part: Code_0;
			}
			return Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (*pos++ != 'r') return Code_0;
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'm':
				if (pos == end) return Code_0;
				if (!is_prefix_of("il", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_permil: Code_0;
			case 'p':
				return pos == end ? CODE_perp: Code_0;
			}
			return Code_0;
		case 'h':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			return pos == end ? CODE_phi: Code_0;
		case 'i':
			return pos == end ? CODE_pi: Code_0;
			if (*pos++ != 'v') return Code_0;
			return pos == end ? CODE_piv: Code_0;
		case 'l':
			if (pos == end) return Code_0;
			if (!is_prefix_of("usmn", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_plusmn: Code_0;
		case 'o':
			if (pos == end) return Code_0;
			if (!is_prefix_of("und", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_pound: Code_0;
		case 'r':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'i':
				if (pos == end) return Code_0;
				if (!is_prefix_of("me", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_prime: Code_0;
			case 'o':
				if (pos == end) return Code_0;
				switch (*pos++) {
				case 'd':
					return pos == end ? CODE_prod: Code_0;
				case 'p':
					return pos == end ? CODE_prop: Code_0;
				}
				return Code_0;
			}
			return Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (*pos++ != 'i') return Code_0;
			return pos == end ? CODE_psi: Code_0;
		}
		return Code_0;
	case 'q':
		if (pos == end) return Code_0;
		if (!is_prefix_of("uot", pos, end)) return Code_0;
		std::advance(pos, 3);
		return pos == end ? CODE_quot: Code_0;
	case 'r':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'A':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_rArr: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'd':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ic", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_radic: Code_0;
			case 'n':
				if (pos == end) return Code_0;
				if (*pos++ != 'g') return Code_0;
				return pos == end ? CODE_rang: Code_0;
			case 'q':
				if (pos == end) return Code_0;
				if (!is_prefix_of("uo", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_raquo: Code_0;
			case 'r':
				if (pos == end) return Code_0;
				if (*pos++ != 'r') return Code_0;
				return pos == end ? CODE_rarr: Code_0;
			}
			return Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("eil", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_rceil: Code_0;
		case 'd':
			if (pos == end) return Code_0;
			if (!is_prefix_of("quo", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_rdquo: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'a':
				if (pos == end) return Code_0;
				if (*pos++ != 'l') return Code_0;
				return pos == end ? CODE_real: Code_0;
			case 'g':
				return pos == end ? CODE_reg: Code_0;
			}
			return Code_0;
		case 'f':
			if (pos == end) return Code_0;
			if (!is_prefix_of("loor", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_rfloor: Code_0;
		case 'h':
			if (pos == end) return Code_0;
			if (*pos++ != 'o') return Code_0;
			return pos == end ? CODE_rho: Code_0;
		case 'l':
			if (pos == end) return Code_0;
			if (*pos++ != 'm') return Code_0;
			return pos == end ? CODE_rlm: Code_0;
		case 's':
			if (pos == end) return Code_0;
			if (!is_prefix_of("quo", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_rsquo: Code_0;
		}
		return Code_0;
	case 's':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'b':
			if (pos == end) return Code_0;
			if (!is_prefix_of("quo", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_sbquo: Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("aron", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_scaron: Code_0;
		case 'd':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ot", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_sdot: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ct", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_sect: Code_0;
		case 'h':
			if (pos == end) return Code_0;
			if (*pos++ != 'y') return Code_0;
			return pos == end ? CODE_shy: Code_0;
		case 'i':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'g':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ma", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_sigma: Code_0;
				if (*pos++ != 'f') return Code_0;
				return pos == end ? CODE_sigmaf: Code_0;
			case 'm':
				return pos == end ? CODE_sim: Code_0;
			}
			return Code_0;
		case 'p':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ades", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_spades: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'b':
				return pos == end ? CODE_sub: Code_0;
				if (*pos++ != 'e') return Code_0;
				return pos == end ? CODE_sube: Code_0;
			case 'm':
				return pos == end ? CODE_sum: Code_0;
			case 'p':
				return pos == end ? CODE_sup: Code_0;
				switch (*pos++) {
				case '1':
					return pos == end ? CODE_sup1: Code_0;
				case '2':
					return pos == end ? CODE_sup2: Code_0;
				case '3':
					return pos == end ? CODE_sup3: Code_0;
				case 'e':
					return pos == end ? CODE_supe: Code_0;
				}
				return Code_0;
			}
			return Code_0;
		case 'z':
			if (pos == end) return Code_0;
			if (!is_prefix_of("lig", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_szlig: Code_0;
		}
		return Code_0;
	case 't':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (*pos++ != 'u') return Code_0;
			return pos == end ? CODE_tau: Code_0;
		case 'h':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'e':
				if (pos == end) return Code_0;
				switch (*pos++) {
				case 'r':
					if (pos == end) return Code_0;
					if (!is_prefix_of("e4", pos, end)) return Code_0;
					std::advance(pos, 2);
					return pos == end ? CODE_there4: Code_0;
				case 't':
					if (pos == end) return Code_0;
					if (*pos++ != 'a') return Code_0;
					return pos == end ? CODE_theta: Code_0;
					if (!is_prefix_of("sym", pos, end)) return Code_0;
					std::advance(pos, 3);
					return pos == end ? CODE_thetasym: Code_0;
				}
				return Code_0;
			case 'i':
				if (pos == end) return Code_0;
				if (!is_prefix_of("nsp", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_thinsp: Code_0;
			case 'o':
				if (pos == end) return Code_0;
				if (!is_prefix_of("rn", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_thorn: Code_0;
			}
			return Code_0;
		case 'i':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'l':
				if (pos == end) return Code_0;
				if (!is_prefix_of("de", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_tilde: Code_0;
			case 'm':
				if (pos == end) return Code_0;
				if (!is_prefix_of("es", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_times: Code_0;
			}
			return Code_0;
		case 'r':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ade", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_trade: Code_0;
		}
		return Code_0;
	case 'u':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'A':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rr", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_uArr: Code_0;
		case 'a':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'c':
				if (pos == end) return Code_0;
				if (!is_prefix_of("ute", pos, end)) return Code_0;
				std::advance(pos, 3);
				return pos == end ? CODE_uacute: Code_0;
			case 'r':
				if (pos == end) return Code_0;
				if (*pos++ != 'r') return Code_0;
				return pos == end ? CODE_uarr: Code_0;
			}
			return Code_0;
		case 'c':
			if (pos == end) return Code_0;
			if (!is_prefix_of("irc", pos, end)) return Code_0;
			std::advance(pos, 3);
			return pos == end ? CODE_ucirc: Code_0;
		case 'g':
			if (pos == end) return Code_0;
			if (!is_prefix_of("rave", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_ugrave: Code_0;
		case 'm':
			if (pos == end) return Code_0;
			if (*pos++ != 'l') return Code_0;
			return pos == end ? CODE_uml: Code_0;
		case 'p':
			if (pos == end) return Code_0;
			if (!is_prefix_of("si", pos, end)) return Code_0;
			std::advance(pos, 2);
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'h':
				return pos == end ? CODE_upsih: Code_0;
			case 'l':
				if (pos == end) return Code_0;
				if (!is_prefix_of("on", pos, end)) return Code_0;
				std::advance(pos, 2);
				return pos == end ? CODE_upsilon: Code_0;
			}
			return Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_uuml: Code_0;
		}
		return Code_0;
	case 'w':
		if (pos == end) return Code_0;
		if (!is_prefix_of("eierp", pos, end)) return Code_0;
		std::advance(pos, 5);
		return pos == end ? CODE_weierp: Code_0;
	case 'x':
		if (pos == end) return Code_0;
		if (*pos++ != 'i') return Code_0;
		return pos == end ? CODE_xi: Code_0;
	case 'y':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'a':
			if (pos == end) return Code_0;
			if (!is_prefix_of("cute", pos, end)) return Code_0;
			std::advance(pos, 4);
			return pos == end ? CODE_yacute: Code_0;
		case 'e':
			if (pos == end) return Code_0;
			if (*pos++ != 'n') return Code_0;
			return pos == end ? CODE_yen: Code_0;
		case 'u':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ml", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_yuml: Code_0;
		}
		return Code_0;
	case 'z':
		if (pos == end) return Code_0;
		switch (*pos++) {
		case 'e':
			if (pos == end) return Code_0;
			if (!is_prefix_of("ta", pos, end)) return Code_0;
			std::advance(pos, 2);
			return pos == end ? CODE_zeta: Code_0;
		case 'w':
			if (pos == end) return Code_0;
			switch (*pos++) {
			case 'j':
				return pos == end ? CODE_zwj: Code_0;
			case 'n':
				if (pos == end) return Code_0;
				if (*pos++ != 'j') return Code_0;
				return pos == end ? CODE_zwnj: Code_0;
			}
			return Code_0;
		}
		return Code_0;
	}
	return Code_0;
}
