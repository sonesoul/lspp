#include "strategy/predicate/ByName.h"
#include "Item.h"
#include "str_sort_key.h"
using namespace predicate;

using std::string;

bool ByName::operator()(const Item& a, const Item& b) {
	return str_sort_key(a.name(), _opt) < str_sort_key(b.name(), _opt);
}