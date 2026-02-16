#pragma once
#include <filesystem>

namespace measure {
	uintmax_t none(const std::filesystem::path& p) {
		return 0;
	}
}