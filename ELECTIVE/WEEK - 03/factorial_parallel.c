#include <stdio.h>
#include <omp.h>

int factorial(int n)
{
    int res = 1;
#pragma omp parallel for reduction(* : res)
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
