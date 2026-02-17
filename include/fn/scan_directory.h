#pragma once
#include <vector>
#include "Measurer.h"
#include "Item.h"

namespace fn {

	std::vector<Item> scan_directory(Path, Measurer);
}