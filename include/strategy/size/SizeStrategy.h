#pragma once
#include "Item.h"
#include "strategy/Strategy.h"

namespace size {
	class SizeStrategy : Strategy {
	public:
		virtual uintmax_t operator()(Item&) = 0;
	};
}