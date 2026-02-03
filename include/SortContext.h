#pragma once
#include <functional>
#include "Item.h"
#include "lspp_flag.h"
#include <iostream>
#include "cmp_pair.h"

class SortContext {

private:
	using Predicate = std::function<bool(cmp_pair&)>;
	
	Predicate _fn;
	
	lspp_flag _flags;

public:
	SortContext(Predicate fn, lspp_flag params) : 
		_fn(fn),
		_flags(params) {
	};

	bool has(lspp_flag flag) const {
		return (_flags & flag) != 0;
	}

	bool compare(const Item& a, const Item& b) const {

		if (a.type() != b.type()) {
			return has(TypeReversed) 
				? b.type() == ItemType::directory 
				: a.type() == ItemType::directory;
		}
		else {
			return _fn(has(Reversed) 
				? cmp_pair(b, a, _flags) 
				: cmp_pair(a, b, _flags));
		}
	}
};