#pragma once
#include <filesystem>

using ItemType = std::filesystem::file_type;
using Path = std::filesystem::path;
using Entry = std::filesystem::directory_entry;

class Item {
	Path _path;
	ItemType _type;
	uintmax_t _size;
	
public:
	Item(Entry entry, uintmax_t size) : 
		_size(size), 
		_path(std::filesystem::absolute(entry.path())), 
		_type(entry.status().type()) {
	}

	const Path& Item::path() const {
		return _path;
	}
	ItemType Item::type() const {
		return _type;
	}
	std::string Item::name() const {
		return path().filename().string();
	}
	uintmax_t Item::size() const {
		return _size;
	}
};