#pragma once
#include <functional>
#include "Item.h"
#include "sort_flags.h"
#include <iostream>
#include "cmp_pair.h"

class SortContext {

private:
	using Predicate = std::function<bool(cmp_pair&)>;
	using PairCreator = std::function<cmp_pair(const Item& a, const Item& b)>;
	
	PairCreator _creator;

	Predicate _fn;
	Predicate _typeComparator;

	lspp_flag _flags;

public:
	SortContext(Predicate fn, lspp_flag params) : 
		_fn(fn),
		_flags(params) {
		
		PairCreator creator = [this](const Item& a, const Item& b) {
			return cmp_pair(a, b, _flags);
		};
		PairCreator rcreator = [this](const Item& a, const Item& b) {
			return cmp_pair(b, a, _flags);
		};

		Predicate typecmp = [this](cmp_pair pair) {
			return pair.a.type() == ItemType::directory;
		};
		Predicate rtypecmp = [this](cmp_pair pair) {
			return pair.b.type() == ItemType::directory;
		};
			
		_creator = has(Reversed) ? rcreator : creator;
		_typeComparator = has(TypeReversed) ? rtypecmp : typecmp;
	};

	bool has(lspp_flag flag) const {
		return (toNum(_flags) & toNum(flag)) != 0;
	}

	bool compare(const Item& a, const Item& b) const {

		if (a.type() != b.type())
			return _typeComparator(cmp_pair(a, b, _flags));

		return _fn(_creator(a, b));
	}

private:
	inline u32 toNum(lspp_flag flags) const {
		return (u32)flags;
	}
};