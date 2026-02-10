#pragma once
#include <utf8proc.h>
#include "PredicateStrategy.h"
#include "lspp_flag.h"

namespace predicate {
	class ByName : public PredicateStrategy {
		
		utf8proc_option_t _opt;

	public:
		ByName(utf8proc_option_t option) : 
			_opt(option) { 
		};

		bool operator()(const Item& a, const Item& b) override;
	};
}