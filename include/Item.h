#pragma once
#include <filesystem>

using ItemType = std::filesystem::file_type;
using Path = std::filesystem::path;
using DirectoryEntry = std::filesystem::directory_entry;

class Item {
	DirectoryEntry _entry;
	Path _path;
	ItemType _type;
	std::string _name;
	bool _isValid;
	uintmax_t _size;

public:
	Item(Path p) {
		try {
			_entry = DirectoryEntry(p);
			_path = std::filesystem::absolute(_entry.path());
			_type = _entry.status().type();
			_name = path().filename().string();
			_size = std::filesystem::file_size(_entry);

			_isValid = true;
		}
		catch (...) {
			_path = Path("");
			_type = ItemType::unknown;
			_name = "";
			
			_isValid = false;
		}
	}

	inline std::string name() const {
		return _name;
	}
	inline bool isValid() const {
		return _isValid;
	}
	inline ItemType type() const {
		return _type;
	}
	inline Path path() const {
		return _path;
	}
	inline uintmax_t size() const { 
		return _size;
	}
};