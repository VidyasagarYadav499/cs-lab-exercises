#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_perfect_num(int num)
{
    if (num <= 0)
    {
        return false;
    }

    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    if (num == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int arr[] = {6, 28, 496, 427, 375, 630, 749, 671, 633, 71, 203, 915, 100, 427, 39, 82, 768, 976, 8128, 33550336};

    for (int i = 0; i < 20; i++)
    {
        if (is_perfect_num(arr[i]) == true)
        {
            printf("perfect num: %d\n", arr[i]);
        }
    }

    return 0;
}