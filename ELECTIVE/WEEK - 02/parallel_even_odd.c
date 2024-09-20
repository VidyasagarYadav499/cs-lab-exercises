// Write an OpenMP C program to check if the given 20 integers are even or
// odd.

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < 20; i++)
    {
        if ((arr[i] % 2) == 0)
        {
            printf("Thread %d; %d is even\n", omp_get_thread_num(), arr[i]);
        }
        else
        {
            printf("Thread %d; %d is odd\n", omp_get_thread_num(), arr[i]);
        }
    }

    return 0;
}