#include "binaryfind.h"

int binaryfind(int *array, int start, int end, int tofind)
{
	int mid;

	if (start > end) {
		return -1;
	}

	assert(array && start >= 0 && end >= 0);

	mid = start + (end - start) / 2;
	if (array[mid] == tofind) {
		return mid;
	} else if (array[mid] > tofind) {
		return binaryfind(array, start, mid - 1, tofind);
	} else {
		return binaryfind(array, mid + 1, end, tofind);
	}
}

