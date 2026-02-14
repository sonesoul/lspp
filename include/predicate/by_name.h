#pragma once
#include <utf8proc.h>
#include "Item.h"
#include "fn/str_sort_key.h"

namespace predicate {
	bool by_name(const Item& a, const Item& b, utf8proc_option_t opt) {
		return 
			fn::str_sort_key(a.name(), opt) 
			< fn::str_sort_key(b.name(), opt);
	}
}