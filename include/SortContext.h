#pragma once
#include "Item.h"
#include "strategy/predicate/PredicateStrategy.h"
#include "strategy/type/TypeStrategy.h"
#include "strategy/adapter/ComparisonAdapter.h"

class SortContext {

private:
	PredicateStrategy* _cmp;
	TypeStrategy* _typecmp;
	ComparisonAdapter* _adapter;
	
public:
	SortContext(PredicateStrategy* cmp, ComparisonAdapter* adapter, TypeStrategy* typecmp) : 
		_cmp(cmp),
		_typecmp(typecmp), 
		_adapter(adapter) {
	};

	bool compare(const Item& a, const Item& b) const {

		if (_typecmp->applicable(a, b)) {
			return (*_typecmp)(a, b);
		}

		return (*_adapter)(a, b, _cmp);
	}
};