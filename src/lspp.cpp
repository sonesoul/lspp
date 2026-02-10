#include <filesystem>
#include <iostream>
#include "Item.h"
#include "Directory.h"
#include "icu.h"
#include "strategy/size.h"
#include "strategy/adapter.h"
#include "strategy/predicate.h"
#include "strategy/type.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	auto base = std::filesystem::current_path();

	lspp_flag flags = (lspp_flag)(RecursiveSize);

	size::Recursive strat{};

	Directory dir(base, strat);
	SortContext ctx = SortContext(new predicate::ByNameCS(), new adapter::Normal(), new type::DirectoriesFirst());

	vector<Item>& items = dir.vec();

	quick_sort(&items[0], &items[items.size() - 1], ctx);
 
	for (size_t i = 0; i < items.size(); i++)
	{
		Item& item = items[i];
		if (item.type() == ItemType::directory)
			cout << "[] ";
		else
			cout << "-- ";
		cout << item.name() << " : " << item.size() << "\n";
	}

	return 0;
}