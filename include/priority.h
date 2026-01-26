#pragma once
#include "Item.h"

namespace priority {
	bool byName(const Item&, const Item&);
	bool bySize(const Item&, const Item&);
	bool byDate(const Item&, const Item&);
}