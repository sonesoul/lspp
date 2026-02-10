#pragma once
#include "ComparisonAdapter.h"
#include "Item.h"
#include "strategy/predicate/PredicateStrategy.h"

namespace adapter {
	class Normal : public ComparisonAdapter {
	public:
		bool operator()(const Item& a, const Item& b, PredicateStrategy* cmp) override {
			return (*cmp)(a, b);
		}
	};
}