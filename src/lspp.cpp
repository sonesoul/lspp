#include <filesystem>
#include <iostream>
#include "Item.h"

#include "measure/all.h"
#include "priority/all.h"
#include "predicate/all.h"
#include "compare/all.h"

#include "fn/scan_directory.h"

using namespace std;

int main(int argCount, char* argValues[]) {
	setlocale(LC_ALL, "");

	auto base = std::filesystem::current_path();

	auto prio = priority::directories;
	auto pred = predicate::by_size;
	auto meas = measure::recursive;
	auto comp = compare::normal;

	auto content = fn::scan_directory(base, meas);
	std::sort(content.begin(), content.end(), [&](const auto& a, const auto& b) { return comp(a, b, prio, pred); });

	for (size_t i = 0; i < content.size(); i++)
	{
		Item& item = content[i];
		if (item.type() == ItemType::directory)
			cout << "[] ";
		else
			cout << "-- ";
		cout << item.name() << " : " << item.size() << "\n";
	}

	return 0;
}