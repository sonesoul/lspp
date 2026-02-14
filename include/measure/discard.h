#pragma once
#include <filesystem>

namespace measure {
	uintmax_t discard(const std::filesystem::path& p) {
		return 0;
	}
}