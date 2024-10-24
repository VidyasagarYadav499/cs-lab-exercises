#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 10000

int main(){
	
	srand(time(NULL));
	
	int count;
	int val = rand() % 100; // Take a random value b/w 0 and 100(excluding). we wll count the occurence of this value.
	
	long int* arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
	
	for(int i = 0; i < SIZE; i++){
		arr[i] = rand() % 100;
	}
	
	for(int i = 0; i < SIZE; i++){
		if(arr[i] == val){
			count++;
		}
	}
	
	printf("The count of %d is: %d", val, count);
	
	return 0;
}
