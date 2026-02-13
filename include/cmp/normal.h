#pragma once
#include "Item.h"
#include "strategy/type/TypeStrategy.h"
#include "strategy/predicate/PredicateStrategy.h"

namespace cmp {
	bool normal(const Item& a, const Item& b, TypeStrategy* typecmp, PredicateStrategy* cmp) {
		return (typecmp->applicable(a, b))
			? (*typecmp)(a, b)
			: (*cmp)(a, b);
	}
}