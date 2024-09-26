#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 500000

int main(){
	int arr[SIZE];
	int sum = 0;

//	#pragma omp parallel
//	{
//		int i;
//		#pragma omp parallel for ordered
//		for(i = 0; i < SIZE; i++){
//			#pragma omp ordered
//			{
//				arr[i] = (i + 1);
//			}
//		}
//		
//		#pragma omp parallel for reduction(+:sum)
//		for(i = 0; i < SIZE; i++){
//			sum += arr[i];
//		}
//	}

	int i;
	for(i = 0; i < SIZE; i++){
		arr[i] = (i + 1);
	}

	#pragma omp parallel for reduction(+:sum)
	for(i = 0; i < SIZE; i++){
		sum += arr[i];
	}
	
	printf("sum: %d", sum);
	
	return 0;
}
