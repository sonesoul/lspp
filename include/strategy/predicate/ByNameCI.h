#pragma once
#include "ByName.h"

namespace predicate {
	//Case Insensitive
	class ByNameCI : public ByName {

	public:
		ByNameCI() : ByName((utf8proc_option_t)(
			UTF8PROC_STABLE
			| UTF8PROC_COMPOSE)) {
		};
	};
}