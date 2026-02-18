#pragma once
#include <unordered_map>
#include <string_view>
#include "lspp_config.h"

namespace fn {
	std::unordered_map<std::string_view, void(*)(lspp_config&)> make_setter_map();
}