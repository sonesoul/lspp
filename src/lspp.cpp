#include <filesystem>
#include <iostream>
#include "Item.h"
#include "Directory.h"
#include "priority.h"
#include "icu.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	auto base = std::filesystem::current_path();

	lspp_flag flags = (lspp_flag)(RecursiveSize);

	Directory dir(base, flags);
	SortContext ctx = SortContext(priority::byName, flags);

	vector<Item>& items = dir.vec();

	quick_sort(&items[0], &items[items.size() - 1], ctx);
 
	for (size_t i = 0; i < items.size(); i++)
	{
		Item& item = items[i];
		if (item.type() == ItemType::directory)
			cout << "[] ";
		else
			cout << "-- ";
		cout << item.name() << "\n";
	}

	return 0;
}