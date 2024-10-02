#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include <math.h>

#define UPPER_BOUND 1
#define RANGE 10000000
#define SEED 100000

void main()
{
    srand(time(NULL));
    // srand(SEED);

    double circle_points = 0, square_points = 0;

    for (size_t i = 0; i < RANGE; i++)
    {
        double x = (double)(rand() % (UPPER_BOUND + 1));
        double y = (double)(rand() % (UPPER_BOUND + 1));

        double value = x * x + y * y;

        if (value <= 1)
        {
            circle_points++;
        }

        square_points++;
    }

    double pi = (circle_points / square_points) * 4;

    printf("%f", pi);
}