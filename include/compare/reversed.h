#pragma once
#include "Item.h"
#include "Prioritizer.h"
#include "Predicate.h"

namespace compare {
	inline bool reversed(const Item& a, const Item& b, Prioritizer prioritize, Predicate compare) {
		auto result = prioritize(a, b);

		if (result == std::nullopt)
			return compare(b, a);

		return result.value();
	}
}