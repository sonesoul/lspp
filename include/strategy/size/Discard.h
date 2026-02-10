#pragma once
#include "SizeStrategy.h"

namespace size {
	class Discard : public SizeStrategy {
	public:
		inline uintmax_t operator()(Item&) override {
			return 0;
		}
	};
}