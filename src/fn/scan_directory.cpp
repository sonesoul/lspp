#include "fn/scan_directory.h"
#include "Item.h"

namespace fn {
	DirectoryContent scan_directory(Path path, Measurer measurer) {
		namespace fs = std::filesystem;

		DirectoryContent content{};

		for (auto& it : fs::directory_iterator(path)) {

			std::error_code ec;
			auto entry = fs::directory_entry(it, ec);

			if (ec) {
				continue;
			}

			content.push_back(std::make_unique<Item>(entry, measurer(it)));
		}

		return content;
	}
}