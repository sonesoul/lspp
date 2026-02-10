#include <filesystem>
#include <iostream>
#include "Item.h"
#include "Directory.h"
#include "SortContext.h"

#include "strategy/size.h"
#include "strategy/adapter.h"
#include "strategy/predicate.h"
#include "strategy/type.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	auto base = std::filesystem::current_path();

	Directory dir(base, 
		new size::Discard());

	SortContext ctx = SortContext(
		new predicate::BySize(), 
		new adapter::Normal(), 
		new type::Discard());

	vector<Item*>& items = dir.vec();

	std::sort(items.begin(), items.end(), [&](const Item* a, const Item* b) { return ctx.compare(*a, *b); });

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