#pragma once
#include "strategy/Strategy.h"

class Item;

class PredicateStrategy : Strategy {
public:
	virtual bool operator()(const Item&, const Item&) = 0;
};