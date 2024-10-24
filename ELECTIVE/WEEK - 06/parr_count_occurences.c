#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 100000

int main(){
	
	srand(time(NULL));
	
	int count = 0;
	int val = rand() % 100; // Take a random value b/w 0 and 100(excluding). we wll count the occurence of this value.
	
	long int* arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
	
	for(int i = 0; i < SIZE; i++){
		arr[i] = rand() % 100;
	}
	
	#pragma omp parallel for
	for(int i = 0; i < SIZE; i++){
		if(arr[i] == val){
			#pragma omp critical
			{
				count++;
			}
		}
	}
	
	
	
	for(int i = 0; i < SIZE; i++){
		if(arr[i] == val){
			printf("%d\t", arr[i]);
		}
	}
	printf("The count of %d is: %d", val, count);
	
	return 0;
}
