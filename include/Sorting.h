#pragma once
#include <functional>
#include "Directory.h"

using Comparer = std::function<bool(const Item&, const Item&)>;

class DirectorySorter {

public:
	void Sort(Directory&, const Comparer&);
};