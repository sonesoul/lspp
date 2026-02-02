#pragma once

class Item;
enum lspp_flag : unsigned int;

struct cmp_pair {
	const Item& a;
	const Item& b;
	const lspp_flag& order;

	cmp_pair(const Item& a, const Item& b, const lspp_flag& order) : 
		a(a), b(b), order(order) {
	}
};