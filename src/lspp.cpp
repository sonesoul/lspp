#include "Item.h"
#include <iostream>
#include <filesystem>
#include "Directory.h"
#include "Sorting.h"
#include "priority.h"
#include "icu.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	Directory dir(Path("D:\\"));
	DirectorySorter sorter = DirectorySorter();
	
	sorter.Sort(dir, priority::byName);

	for (auto& i : dir.vec()) {
		cout << i.name() << '\n';
	}

	return 0;
}