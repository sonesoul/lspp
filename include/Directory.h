#pragma once
#include <vector>
#include "Item.h"
#include "SortContext.h"
#include "quick_sort.h"

class Directory {
	std::vector<Item> _items;

public: 
	Directory(const Path& path, lspp_flag flags) {
		
		namespace fs = std::filesystem;
		bool recursive = (flags & lspp_flag::RecursiveSize) != 0;
		
		for (auto& it : fs::directory_iterator(path)) {
			Item item = Item(it.path());
			
			if (!item.isValid())
				continue;

			if (recursive && item.type() == ItemType::directory) {
				std::error_code ec;
				uintmax_t size = 0;

				auto iterator = fs::recursive_directory_iterator(
					item.path(),
					fs::directory_options::skip_permission_denied,
					ec);

				for (auto& it : iterator) {
					size += it.file_size();
				}

				item.size() = size;
			}

			_items.push_back(item);
		}
	}

	inline std::vector<Item>& vec() {
		return _items;
	}
};