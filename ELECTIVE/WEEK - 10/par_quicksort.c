#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//int partition(int arr[], int low, int high) {
//    int pivotIndex = high;
//    int lowIndex = low;
//    int highIndex = high - 1;
//
//    while (true) {
//        while (arr[lowIndex] < arr[pivotIndex]) {
//            lowIndex++;
//        }
//
//        while (arr[highIndex] > arr[pivotIndex] && highIndex > 0) {
//            highIndex--;
//        }
//
//        if (lowIndex >= highIndex) break;
//        else swap(&arr[lowIndex], &arr[highIndex]);
//    }
//
//    swap(&arr[lowIndex], &arr[pivotIndex]);
//
//    return lowIndex;
//}

int partition(int arr[], int low, int high) {
    int pivotIndex = low;
    int lowIndex = low;
    int highIndex = high;

    while (lowIndex < highIndex) {
        while (arr[lowIndex] <= arr[pivotIndex] && lowIndex <= high - 1) {
            lowIndex++;
        }

        while (arr[highIndex] > arr[pivotIndex] && highIndex >= low + 1) {
            highIndex--;
        }
        
        if (lowIndex < highIndex) {
            swap(&arr[lowIndex], &arr[highIndex]);
        }
    }
    
    swap(&arr[low], &arr[highIndex]);
    return highIndex;
}

void quicksort(int arr[], int low, int high) {
    if (low >= high) return;

    int pi = partition(arr, low, high);

    #pragma omp task if(high - low > 1000)
    quicksort(arr, low, pi - 1);

    #pragma omp task if(high - low > 1000)
    quicksort(arr, pi + 1, high);

    #pragma omp taskwait // wait for tasks to finish.
}

int main() {
	srand(time(NULL));
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 200;
    }

	#pragma omp parallel
	{
		#pragma omp single
    	quicksort(arr, 0, SIZE - 1);
	}

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

