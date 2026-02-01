#include "Item.h"
#include <iostream>
#include <filesystem>
#include "Directory.h"
#include "priority.h"
#include "icu.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	Directory dir(Path("D:\\"));
	SortContext order = SortContext(priority::byName, (sort_flags)(CaseSensitive | TypeReversed | Reversed));

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