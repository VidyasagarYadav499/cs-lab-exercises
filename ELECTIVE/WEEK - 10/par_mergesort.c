# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <omp.h>

# define SIZE 10

void merge(int arr[],int low, int mid, int high){
	int n1 = mid - low + 1;
	int n2 = high - mid;
	
	int left[n1];
	int right[n2];
	
	for(int i = 0; i < n1; i++){
		left[i] = arr[low + i];
	}
	
	for(int i = 0; i < n2; i++){
		right[i] = arr[mid + 1 + i];
	}
	
	// Time to merge.
	int i = 0, j = 0, k = low;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
			k++;
		}
		else{
			arr[k] = right[j];
			j++;
			k++;
		}
	}
	
	while(i < n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	
	while(j < n2){
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int low, int high){
	if(low >= high) return;
	int mid = (low + high) / 2;
	
	#pragma omp task shared(arr)
	mergesort(arr, low, mid);
	
	#pragma omp task shared(arr)
	mergesort(arr, mid + 1, high);
	
	#pragma omp taskwait
	merge(arr, low, mid , high);
}

int main(){
	srand(time(NULL));
	int arr[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 200;
    }
    
    double start = omp_get_wtime();
    
    #pragma omp parallel
    {
    	#pragma omp single
    	mergesort(arr, 0, SIZE - 1);
	}
	
	double end = omp_get_wtime();

    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
//    printf("\nTime taken: %f", end - start);

    
	return 0;
}
