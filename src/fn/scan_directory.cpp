#include "fn/scan_directory.h"
#include "Item.h"

namespace fn {
	std::vector<Item> scan_directory(Path path, Measurer measurer) {
		namespace fs = std::filesystem;

		std::vector<Item> content{};
		uintmax_t size = 0;

		std::error_code ec;
		for (auto& entry : fs::directory_iterator(path, fs::directory_options::skip_permission_denied, ec)) {
			++size;
		}

		content.reserve(size);

		for (auto& entry : fs::directory_iterator(path, fs::directory_options::skip_permission_denied, ec)) {
			content.emplace_back(entry, measurer(entry));
		}

		return content;
	}
}