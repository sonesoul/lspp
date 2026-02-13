#include <filesystem>
#include <iostream>
#include "Item.h"
#include "Directory.h"
#include "Comparator.h"

#include "strategy/size.h"
#include "strategy/predicate.h"
#include "strategy/type.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	auto base = std::filesystem::current_path();

	Directory dir(base, new size::Discard());

	auto tc = new type::Discard();
	auto pr = new predicate::BySize();

	vector<Item*>& items = dir.vec();

	std::sort(items.begin(), items.end(), [&](const Item* a, const Item* b) { return cmp::normal(*a, *b, tc, pr); });

	for (size_t i = 0; i < items.size(); i++)
	{
		Item& item = *items[i];
		if (item.type() == ItemType::directory)
			cout << "[] ";
		else
			cout << "-- ";
		cout << item.name() << " : " << item.size() << "\n";
	}

	return 0;
}