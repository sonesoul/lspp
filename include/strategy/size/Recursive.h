#include "SizeStrategy.h"

namespace size {
	class Recursive : public SizeStrategy {
	public:
		uintmax_t operator()(Item&) override;
	};
}