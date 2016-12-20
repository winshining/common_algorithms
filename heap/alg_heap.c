#include "alg.h"

/*
 * Min heap
 */
static
void alg_heap_adjust(ssize_t *array, ssize_t start, ssize_t end)
{
    ssize_t temp;
    ssize_t i;

    assert(array && (start >= 0) && (end >= start));

    temp = array[start];

    for (i = 2 * start + 1; i <= end; i = 2 * i + 1) {
        if (i < end && (array[i] > array[i+1])) {
            i++;
        }

        if (temp < array[i]) {
            break;
        }

        array[start] = array[i];
        start = i;
    }

    array[start] = temp;
}

void alg_heap_sort(ssize_t *array, ssize_t size)
{
    ssize_t temp;
    ssize_t i;

    assert(array && size > 0);

    // construct min heap
    for (i = size/2 - 1; i >= 0; i--) {
        alg_heap_adjust(array, i, size - 1);
    }

    for (i = size - 1; i > 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // heap smaller and smaller
        alg_heap_adjust(array, 0, i - 1);
    }
}

