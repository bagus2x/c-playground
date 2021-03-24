#define TRUE 1
#define FALSE 0


int bs_recursive(int *array, int left, int right, int x);

/* [1, 2, 3, 4 , 5, 6, 7, 8] */
int binary_search_iterative(int *array, int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid_index;

    while (left <= right)
    {
        mid_index = left + ((right - left) / 2);

        if (array[mid_index] == x)
            return TRUE;
        else if (x < array[mid_index])
            right = mid_index - 1;
        else
            left = mid_index + 1;
    }
}

int binary_search_recursive(int *array, int n, int x)
{
    return bs_recursive(array, 0, n - 1, x);
}

int bs_recursive(int *array, int left, int right, int x)
{
    if (left > right)
        return FALSE;

    int mid_index = left + ((right - left) / 2);

    if (array[mid_index] == x)
        return TRUE;
    else if (x < array[mid_index])
        return bs_recursive(array, left, mid_index - 1, x);
    else
        return bs_recursive(array, right, mid_index + 1, x);
}