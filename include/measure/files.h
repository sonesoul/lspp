#pragma once
#include <filesystem>

namespace measure {
	uintmax_t files(const std::filesystem::path& p) {
		namespace fs = std::filesystem;

		return fs::status(p).type() != fs::file_type::directory
			? fs::file_size(p)
			: 0;
	}
}