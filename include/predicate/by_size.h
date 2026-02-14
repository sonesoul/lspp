#pragma once
#include "Item.h"

namespace predicate {
	bool by_size(const Item& a, const Item& b) {
		return a.size() < b.size();
	}
}