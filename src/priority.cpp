#include <utf8proc.h>
#include "cmp_pair.h"
#include "priority.h"
#include "sort_flags.h"

using std::string;

namespace priority {

	static std::string sort_key(const std::string& s, utf8proc_option_t opt) {
		utf8proc_uint8_t* out = nullptr;
		utf8proc_map((const utf8proc_uint8_t*)s.c_str(), s.size(), &out, opt);

		std::string result = out ? std::string((char*)out) : std::string(s);

		free(out);

		return result;
	}

	bool byName(const cmp_pair& pair) {
		utf8proc_option_t opt = (utf8proc_option_t)(UTF8PROC_STABLE | UTF8PROC_COMPOSE);

		if ((pair.order & CaseSensitive) == 0) {
			opt = (utf8proc_option_t)(opt | UTF8PROC_CASEFOLD);
		}

		return sort_key(pair.a.name(), opt) < sort_key(pair.b.name(), opt);
	}
	bool bySize(const cmp_pair& pair) {
		return pair.a.size() < pair.b.size();
	}
	bool byDate(const cmp_pair& pair) {
		return false;
	}
}