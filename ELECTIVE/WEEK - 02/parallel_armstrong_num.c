#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <omp.h>

bool is_armstrong(int num)
{
	int count = 0;
	int num_copy = num;
	while (num_copy)
	{
		count++;
		num_copy /= 10;
	}
	num_copy = num;
	int res = 0;
	while (num_copy)
	{
		res += pow(num_copy % 10, count);
		num_copy /= 10;
	}

	return num == res;
}

void main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 123, 495, 563, 106, 35, 645, 349};

	#pragma omp parallel for num_threads(4)
	for (int i = 0; i < 20; i++)
	{

		if (is_armstrong(arr[i]))
		{
			printf("thread %d: %d\n", omp_get_thread_num(), arr[i]);
		}	
	}
}
