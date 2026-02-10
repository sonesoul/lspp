#pragma once
#include "strategy/Strategy.h"

class Item;

class TypeStrategy : public Strategy {
public:
	virtual bool applicable(const Item&, const Item&) = 0;
	virtual bool operator()(const Item&, const Item&) = 0;
};