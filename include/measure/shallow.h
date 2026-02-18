#pragma once
#include <filesystem>

namespace measure {
	inline uintmax_t shallow(const std::filesystem::path& p) {
		return std::filesystem::file_size(p);
	}
}