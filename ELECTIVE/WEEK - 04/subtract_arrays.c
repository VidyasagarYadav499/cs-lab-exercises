#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h> 

#define SIZE 100

int main(){
	srand(time(0));
	
	int arr1[SIZE];
	int arr2[SIZE];
	int arr3[SIZE];
	
	for(int i = 0; i < SIZE; i++){
		arr1[i] = rand() % 100;
	}
	
	for(int i = 0; i < SIZE; i++){
		arr2[i] = rand() % 100;
	}
	
	#pragma omp parallel for
	for(int i = 0; i < SIZE; i++){
		arr3[i] = arr2[i] - arr1[i];
	}
	
	printf("Array 1:\n");
	for(int i = 0; i < SIZE; i++){
		printf("%d\t", arr1[i]);
	}
	printf("\n\n");
	
	printf("Array 2:\n");
	for(int i = 0; i < SIZE; i++){
		printf("%d\t", arr2[i]);
	}
	printf("\n\n");

	printf("Array 3 (arr2 - arr1):\n");
	for(int i = 0; i < SIZE; i++){
		printf("%d\t", arr3[i]);
	}
	
	return 0;
}

