#include "bubble_sort.h"

int main()
{
    int array[] =  {4, 1, 7, 3, 2, 0, 14, 6, 5, 9};
    bubble_sort(array, sizeof(array) / sizeof(int));
    bsprint(array, sizeof(array) / sizeof(int));
}