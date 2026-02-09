#pragma once
#include <vector>
#include "Item.h"
#include "SortContext.h"
#include "quick_sort.h"
#include "strategy/size/SizeStrategy.h"

class Directory {
	std::vector<Item> _items;

public: 
	Directory(const Path& path, SizeStrategy& size) {
		
		for (auto& it : std::filesystem::directory_iterator(path)) {
			Item item = Item(it.path());
			
			if (!item.isValid())
				continue;
			
			item.size() = size(item);

			_items.push_back(item);
		}
	}

	inline std::vector<Item>& vec() {
		return _items;
	}
};