#include "strategy/size/Recursive.h"
using namespace size;
namespace fs = std::filesystem;

uintmax_t Recursive::operator()(Item& item) {
	if (item.type() != ItemType::directory) {
		return fs::file_size(item.path());	
	}

	std::error_code ec;
	uintmax_t size = 0;

	auto iterator = fs::recursive_directory_iterator(
		item.path(),
		fs::directory_options::skip_permission_denied,
		ec);

	for (auto& it : iterator) {
		size += it.file_size();
	}

	return size;
}