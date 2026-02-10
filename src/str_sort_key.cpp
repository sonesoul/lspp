#include "str_sort_key.h"
using std::string;

string str_sort_key(const string& s, utf8proc_option_t opt) {
	utf8proc_uint8_t* out = nullptr;
	utf8proc_map((const utf8proc_uint8_t*)s.c_str(), s.size(), &out, opt);

	string result = out
		? string((char*)out)
		: string(s);

	free(out);

	return result;
}