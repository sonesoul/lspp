#include "TypeStrategy.h"
#include "Item.h";

namespace type {
	class FilesFirst : public TypeStrategy {
	public:
		inline bool applicable(const Item& a, const Item& b) override {
			return a.type() != b.type();
		}
		inline bool operator()(const Item&, const Item& b) override {
			return b.type() == ItemType::directory;
		}
	};
}