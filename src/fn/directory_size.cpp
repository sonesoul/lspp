#include "fn/directory_size.h"

uintmax_t fn::directory_size(const std::filesystem::path p) {
	namespace fs = std::filesystem;

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