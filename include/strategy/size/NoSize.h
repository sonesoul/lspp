#pragma once
#include "SizeStrategy.h"

namespace size {
	class NoSize : public SizeStrategy {
	public:
		inline uintmax_t operator()(Item&) override {
			return 0;
		}
	};
}