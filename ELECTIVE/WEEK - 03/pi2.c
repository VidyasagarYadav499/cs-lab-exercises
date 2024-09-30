#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UPPER_BOUND 1
#define RANGE 100000000

int main() 
{
    srand(time(NULL));

    int circle_points = 0, square_points = 0;

    for (int i = 0; i < RANGE; i++)
    {
        // double x = (double)rand() / RAND_MAX;
        // double y = (double)rand() / RAND_MAX; 

        double x = (double)(rand() % (UPPER_BOUND + 1));
        double y = (double)(rand() % (UPPER_BOUND + 1));

        double value = x * x + y * y;

        if (value <= 1.0)
        {
            circle_points++;
        }

        square_points++;
    }

    double pi = ((double)circle_points / square_points) * 4;

    printf("%f\n", pi);

    return 0; 
}
