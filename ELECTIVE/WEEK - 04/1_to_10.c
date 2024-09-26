#include <stdio.h>
#include <omp.h>

int main() {
	int i;
    #pragma omp parallel for private(i)
    for (i = 1; i<= 10; i++){
        printf("Thread %d:	%d\n", omp_get_thread_num(), i);
    }

    return 0;
}

//int main(){
//    #pragma omp parallel for ordered
//    for (int i = 1; i<= 10; i++){
//        #pragma omp ordered
//        {
//            printf("%d ", i);
//        }
//    }
//
//    return 0;
//}


