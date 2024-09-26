#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int arr[1000];
    int max = 0;
    srand(time(NULL));
    
	int i;
    for ( i = 0; i < 1000; i++){
        arr[i] = rand() % 100;
    }
	
	for ( i = 0; i < 1000; i++){
        printf("%d	", arr[i]);
    }
	
	printf("\n\n");
    #pragma omp parallel for reduction(max:max) private(i)
    for (i = 0; i <1000; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("max: %d\n", max);

    return 0;
}

