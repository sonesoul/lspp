#pragma once

class Item;

class PredicateStrategy {
public:
	virtual ~PredicateStrategy() = default;
	virtual bool operator()(const Item&, const Item&) = 0;
};