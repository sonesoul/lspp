#pragma once
#include "Item.h"

bool Item::tryInit(Path p) {
	try {
		auto entry = std::filesystem::directory_entry(p);
		_path = std::filesystem::absolute(entry.path());
		_type = entry.status().type();
		_size = 0;
	}
	catch (...) {
		_path = Path("");
		_type = ItemType::unknown;
		_size = 0;

		return false;
	}

	return true;
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

uintmax_t& Item::size() {
	return _size;
}