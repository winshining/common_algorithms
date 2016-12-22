#include "alg.h"

void alg_quick_sort(ssize_t *array, ssize_t left, ssize_t right)
{
    ssize_t temp, i, j;

    if (left < right) {
        temp = array[left], i = left, j = right;

        while (i < j) {
            while (i < j && array[j] > temp)
                j--;

            if (i < j)
                array[i++] = array[j];

            while (i < j && array[i] <= temp)
                i++;

            if (i < j)
                array[j--] = array[i];
        }

        array[i] = temp;
        alg_quick_sort(array, left, i - 1);
        alg_quick_sort(array, i + 1, right);
    }
}
