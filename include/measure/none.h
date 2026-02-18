#pragma once
#include <filesystem>

namespace measure {
	inline uintmax_t none(const std::filesystem::path& p) {
		return 0;
	}
}