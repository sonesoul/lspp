#pragma once
#include "Item.h"

class SizeStrategy {
public:
	virtual ~SizeStrategy() = default;
	virtual uintmax_t operator()(Item&) = 0;
};