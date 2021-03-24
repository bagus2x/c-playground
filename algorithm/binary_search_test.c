#include <stdio.h>
#include "binary_search.h"

int main()
{
    int array[] =  {11, 13, 14, 16, 17, 18, 19, 23, 27};
    int bool = binary_search_iterative(array, sizeof(array) / sizeof(int), 23);
    printf("iter: %d\n", bool);

    int bool2 = binary_search_recursive(array, sizeof(array) / sizeof(int), 17);
    printf("recv: %d\n", bool2);

    return 0;
}