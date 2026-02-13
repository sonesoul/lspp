#pragma once

class PredicateStrategy;
class Item;

class ComparisonAdapter {
public:
	virtual ~ComparisonAdapter() = default;
	virtual bool operator()(const Item&, const Item&, PredicateStrategy* str) = 0;
};