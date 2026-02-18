#pragma once
#include "Item.h"
#include "fn/directory_size.h"

namespace measure {
	inline uintmax_t recursive(const std::filesystem::path& p) {
		auto itemType = std::filesystem::status(p).type();

		return 
			itemType == ItemType::directory 
			? fn::directory_size(p) 
			: std::filesystem::file_size(p);
	}
}