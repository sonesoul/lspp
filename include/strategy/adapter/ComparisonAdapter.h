#pragma once
#include "strategy/Strategy.h"

class PredicateStrategy;
class Item;

class ComparisonAdapter : public Strategy {
public:
	virtual bool operator()(const Item&, const Item&, PredicateStrategy* str) = 0;
};