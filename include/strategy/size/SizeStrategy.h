#pragma once
#include "Item.h"
#include "strategy/Strategy.h"

class SizeStrategy : Strategy {
public:
	virtual uintmax_t operator()(Item&) = 0;
};