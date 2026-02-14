#pragma once
#include "Item.h"
#include "Prioritizer.h"
#include "Predicate.h"

namespace compare {
	bool normal(const Item& a, const Item& b, Prioritizer prioritize, Predicate compare) {
		auto result = prioritize(a, b);

		if (result == std::nullopt)
			return compare(a, b);

		return result.value();
	}
}