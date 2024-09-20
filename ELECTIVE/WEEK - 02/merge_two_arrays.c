#include <stdio.h>

int main()
{
    int arr1[] = {1, 2, 6, 8, 12};
    int arr2[] = {3, 4, 5, 9, 11, 13, 22};
    int n1 = 5, n2 = 7;
    int i = 0, j = 0, k = 0;
    int m[n1 + n2];
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            m[k] = arr1[i];
            i += 1;
        }
        else if (arr2[j] <= arr1[i])
        {
            m[k] = arr2[j];
            j += 1;
        }
        k += 1;
    }
    if (i < n1)
    {
        for (int x = i; x < n1; x++)
        {
            m[k] = arr1[x];
            k += 1;
        }
    }
    if (j < n2)
    {
        for (int x = j; x < n2; x++)
        {
            m[k] = arr2[x];
            k += 1;
        }
    }
    for (int x = 0; x < k; x++)
    {
        printf("%d | ", m[x]);
    }
}
