#include <filesystem>
#include <iostream>

#include "Item.h"

#include "measure/all.h"
#include "priority/all.h"
#include "predicate/all.h"
#include "compare/all.h"

#include "fn/scan_directory.h"
#include "fn/make_setter_map.h"
#include <windows.h>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

	try
	{
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);

		auto base = fs::current_path();

		auto setterMap = fn::make_setter_map();
		auto config = lspp_config(
			measure::files,
			priority::directories,
			compare::normal,
			predicate::by_name_ci);

		for (size_t i = 1; i < argc; ++i) {
			auto param = argv[i];

			auto it = setterMap.find(param);
			if (it != setterMap.end()) {
				it->second(config);
			}
			else if (fs::exists(param) &&
				fs::is_directory(param)) {
				base = fs::path(param);
			}
		}

		std::cout << base.string() << "\n";

		auto prio = config.get<Prioritizer>();
		auto pred = config.get<Predicate>();
		auto meas = config.get<Measurer>();
		auto comp = config.get<Comparator>();

		auto content = fn::scan_directory(base, meas);
		
		std::sort(content.begin(), content.end(), [&](const auto& a, const auto& b) { return comp(a, b, prio, pred); });

		std::vector<std::string> sizeMeasures = { "B", "KB", "MB", "GB", "TB", "PB" };

		for (size_t i = 0; i < content.size(); i++)
		{
			Item& item = content[i];
			if (item.type() == ItemType::directory)
				std::cout << "[] ";
			else
				std::cout << "-- ";

			auto size = item.size();
			size_t measureIndex = 0;

			while (size >= 1024 && measureIndex < sizeMeasures.size()) {
				size /= 1024;
				++measureIndex;
			}

			std::cout << item.name() << " : " << size << sizeMeasures[measureIndex] << "\n";
		}

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
		return 0;
	}
	return 0;
}