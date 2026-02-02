#pragma once
#include <vector>
#include "Item.h"
#include "SortContext.h"
#include "quick_sort.h"

class Directory {
	std::vector<Item> _items;

public: 
	Directory(const Path& path) {
		
		for (auto& it : std::filesystem::directory_iterator(path)) {
			Item item = Item(it.path());
			
			if (!item.isValid())
				continue;
			
			_items.push_back(item);
		}
	}

	inline void sort(const SortContext& order) {
		quick_sort(&_items[0], &_items[_items.size() - 1], order);
	}

	inline std::vector<Item>& vec() {
		return _items;
	}
};