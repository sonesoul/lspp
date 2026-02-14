#pragma once
#include <vector>
#include <memory>
#include "Measurer.h"
#include "Item.h"

using DirectoryContent = std::vector<std::unique_ptr<Item>>;

namespace fn {

	DirectoryContent scan_directory(Path, Measurer);
}