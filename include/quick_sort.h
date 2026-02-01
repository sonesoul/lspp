#pragma once
#include <vector>
#include "Item.h"
#include "SortContext.h"

void quick_sort(Item* left, Item* right, const SortContext& ctx);