#include <stdio.h>

void insertion_sort(int *array, int n)
{
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        int key = array[i];
        
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key; 
    }
}

void print(int *array, int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int main()
{
    int array[] = {6, 3, 4, 2, 9, 10, 5, 1, 8, 7};
    insertion_sort(array, sizeof(array) / sizeof(int));
    print(array, sizeof(array) / sizeof(int));
    return 0;
}