#pragma once
#include <filesystem>
#include "ItemType.h"

struct Item {
	ItemType type;
	std::filesystem::path absolutePath;

	Item(std::filesystem::path ap, ItemType t) : 
		absolutePath(ap), 
		type(t) {
	}
};