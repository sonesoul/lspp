#pragma once

class Item;
enum sort_flags : unsigned int;

struct cmp_pair {
	const Item& a;
	const Item& b;
	const sort_flags& order;

	cmp_pair(const Item& a, const Item& b, const sort_flags& order) : 
		a(a), b(b), order(order) {
	}
};