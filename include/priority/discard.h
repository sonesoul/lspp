#pragma once
#include "Item.h"
#include <optional>

namespace priority {

	std::optional<bool> discard(const Item& a, const Item& b) {
		return std::nullopt;
	}
}