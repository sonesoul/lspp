#pragma once
#include <filesystem>

using ItemType = std::filesystem::file_type;
using Path = std::filesystem::path;

class Item {
	Path _path;
	ItemType _type;
	uintmax_t _size;
	
public:
	bool tryInit(Path p);

	const Path& path() const;
	ItemType type() const;
	std::string name() const;

	uintmax_t size() const;
	uintmax_t& size();
};