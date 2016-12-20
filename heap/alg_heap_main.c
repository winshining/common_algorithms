#include "alg.h"

int main()
{
    ssize_t i;
    ssize_t array[] = {-10, -2, 10, 8, 3, 2, 4, 6, 5, 0, -3, 1, 7};

    alg_heap_sort(array, sizeof(array)/sizeof(ssize_t));

    for (i = 0; i < sizeof(array)/sizeof(ssize_t); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
