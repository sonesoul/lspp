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

	Directory dir(base);
	SortContext order = SortContext(priority::byName, (lspp_flag)(None));

	dir.sort(order);

	vector<Item>& items = dir.vec();
 
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