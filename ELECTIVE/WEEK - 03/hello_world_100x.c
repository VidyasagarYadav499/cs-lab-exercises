#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
#pragma omp parallel for
    for (i = 0; i < 100; i++)
    {
        printf("Hello World from thread %d\n", omp_get_thread_num());
    }

    return 0;
}
