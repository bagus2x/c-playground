#include <stdio.h>

void bubble_sort(int *array, int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++)
        {
            int temp = array[j + 1];
            if(array[j] > temp)
            {
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bsprint(int *array, int size)
{
    printf("[");
    for(int i = 0; i < size; i++)
    {
        printf("%d", *(array + i));
        if(i != size - 1)
            printf(", ");
    }
    printf("]");
}