#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 10000

int main(){
	int arr[SIZE];
	int new_arr[SIZE];
	int i;
	
	for(i = 0; i < SIZE; i++){
		arr[i] = i + 1;
	}
	
	#pragma omp parallel for private(i)
	for(i = 0; i < SIZE; i++){
		arr[i] *= arr[i];
	}
	
	for(i = 0; i < SIZE; i++){
		printf("%d	", arr[i]);
	}
	
	return 0;
}

