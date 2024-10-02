#include <stdio.h>
#include <omp.h>

int main(){
		
	#pragma omp parallel for schedule(dynamic)
	for(int i = 0; i < 100; i++){
		printf("hello world at index %d from thread-%d\n", i , omp_get_thread_num());
	}
	
	return 0;
}
