#include <filesystem>
#include <iostream>

#include "Item.h"

#include "measure/all.h"
#include "priority/all.h"
#include "predicate/all.h"
#include "compare/all.h"

#include "fn/scan_directory.h"
#include "fn/make_setter_map.h"

using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	auto setterMap = fn::make_setter_map();
	auto config = lspp_config(
		measure::files, 
		priority::directories, 
		compare::normal, 
		predicate::by_name_ci);
	
	for (size_t i = 0; i < argc; ++i) {
		auto param = argv[i];

		if (setterMap.find(param) != setterMap.end()) {
			setterMap[param](config);
		}
	}

	auto base = std::filesystem::current_path();
	
	auto prio = config.get<Prioritizer>();
	auto pred = config.get<Predicate>();
	auto meas = config.get<Measurer>();
	auto comp = config.get<Comparator>();

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