#pragma once
#include "ByName.h"

namespace predicate {
	//Case Sensitive
	class ByNameCS : public ByName {

	public:
		ByNameCS() : ByName((utf8proc_option_t)(
			UTF8PROC_STABLE 
			| UTF8PROC_COMPOSE 
			| UTF8PROC_CASEFOLD)){
		};
	};
}