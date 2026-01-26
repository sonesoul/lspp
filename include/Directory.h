#pragma once
#include <vector>
#include "Item.h"

class Directory {
	std::vector<Item> _items;
	 
public: 
	Directory(Path& path) {
		for (auto& it : std::filesystem::directory_iterator(path)) {
			Item item = Item(it.path());
			
			if (item.isValid())
				_items.push_back(item);
		}
	}

	inline std::vector<Item>& vec() {
		return _items;
	}
};