#include "TypeStrategy.h"
#include "Item.h"

namespace type {
	class DirectoriesFirst : public TypeStrategy {
	public:
		inline bool applicable(const Item& a, const Item& b) override {
			return a.type() != b.type();
		}
		inline bool operator()(const Item& a, const Item&) override {
			return a.type() == ItemType::directory;
		}
	};
}