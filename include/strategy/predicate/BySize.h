#pragma once
#include "PredicateStrategy.h"
#include "lspp_flag.h"
#include "Item.h"

namespace predicate {
	class BySize : public PredicateStrategy {

	public:
		bool operator()(const Item& a, const Item& b) override {
			return a.size() > b.size();
		}
	};
}