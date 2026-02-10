#include "TypeStrategy.h"
#include "Item.h";

namespace type {
	class Discard : public TypeStrategy {
	public:
		inline bool applicable(const Item& a, const Item& b) override {
			return false;
		}
		inline bool operator()(const Item&, const Item& b) override {
			return false;
		}
	};
}