#pragma once
#include <vector>
#include "Item.h"
#include "strategy/size/SizeStrategy.h"

class Directory {
	std::vector<Item*> _items;

public: 
	Directory(const Path& path, SizeStrategy* size) {
		
		for (auto& it : std::filesystem::directory_iterator(path)) {
			Item* item = new Item();
			
			if (!item->tryInit(it.path())) {
				delete item;
				continue;
			}
			
			item->size() = (*size)(*item);

			_items.push_back(item);
		}
	}

	~Directory() {
		for (auto& i : _items) {
			delete i;
		}
	}

	inline std::vector<Item*>& vec() {
		return _items;
	}
};