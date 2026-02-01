#include "quick_sort.h"

void quick_sort(Item* left, Item* right, const SortContext& ctx) {
	
	if (left >= right)
		return;

	Item pivot = left[(right - left) / 2];

	Item* i = left - 1;
	Item* j = right + 1;

	while (true) {
		do {
			++i;
		} while (ctx.compare(*i, pivot));

		do {
			--j;
		} while (ctx.compare(pivot, *j));

		if (i >= j)
			break;

		std::swap(*i, *j);
	}

	quick_sort(left, j, ctx);
	quick_sort(j + 1, right, ctx);
}