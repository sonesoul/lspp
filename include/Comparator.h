#pragma once
#include "cmp/normal.h" 
#include "cmp/reversed.h"

using Comparator = bool(*)(const Item&, const Item&, TypeStrategy*, PredicateStrategy*);