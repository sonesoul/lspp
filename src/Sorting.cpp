#include <iostream>
#include "Sorting.h"

void partition(std::vector<Item>& vec, Comparer cmp, size_t start, size_t end) {

	if (start >= end)
		return;

	const Item& pivot = vec[end];
	size_t left = start;

	for (int j = start; j <= end - 1; j++) {
		if (!cmp(vec[j], pivot)) {
			std::swap(vec[left], vec[j]);
			++left;
		}
	}
	
	std::swap(vec[left], vec[end]);

	partition(vec, cmp, start, left - 1);
	partition(vec, cmp, left + 1, end);
}

void DirectorySorter::Sort(Directory& dir, const Comparer& cmp) {
	std::vector<Item>& vec = dir.vec();
	partition(vec, cmp, 0, vec.size() - 1);
}