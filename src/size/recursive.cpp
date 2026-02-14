#include "measure/recursive.h"
namespace fs = std::filesystem;

namespace measure {
	uintmax_t recursive(const std::filesystem::path& p) {

		if (fs::status(p).type() != ItemType::directory) {
			return fs::file_size(p);
		}

		std::error_code ec;
		uintmax_t size = 0;

		auto iterator = fs::recursive_directory_iterator(
			p,
			fs::directory_options::skip_permission_denied,
			ec);

		for (auto& it : iterator) {
			size += it.file_size();
		}

		return size;
	}
}