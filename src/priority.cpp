#include "priority.h"
#include <utf8proc.h>

using std::string;

namespace priority {
	
	static std::string sortKey(const std::string& s) {
		utf8proc_uint8_t* out = nullptr;
		utf8proc_option_t opt = (utf8proc_option_t)(UTF8PROC_STABLE | UTF8PROC_COMPOSE | UTF8PROC_CASEFOLD);

		utf8proc_map((const utf8proc_uint8_t*)s.c_str(), s.size(), &out, opt);

		std::string result = out ? std::string((char*)out) : std::string(s);
		
		free(out);

		return result;
	}

	bool byName(const Item& left, const Item& right) {
		return sortKey(left.name()) > sortKey(right.name());
	}
	bool bySize(const Item& left, const Item& right) {
		return false;
	}
	bool byDate(const Item& left, const Item& right) {
		return false;
	}
}