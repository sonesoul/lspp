#pragma once
#include "SizeStrategy.h"

namespace size {
	class Shallow : public SizeStrategy {
	public:
		inline uintmax_t operator()(Item& item) override {
			return std::filesystem::file_size(item.path());
		}
	};
}