#include "binaryfind.h"

int
main()
{
	int test[] = { -1, 0, 2, 2, 3, 5, 8, 10, 13, 17, 20 };

	int index = binaryfind(test, 0, sizeof(test)/ sizeof(test[0]) - 1, 2);
	printf("index = %d\n", index);

	index = binaryfind(test, 0, sizeof(test) / sizeof(test[0]) - 1, -3);
	printf("index = %d\n", index);

	index = binaryfind(test, 0, sizeof(test) / sizeof(test[0]) - 1, 20);
	printf("index = %d\n", index);

	return 0;
}

