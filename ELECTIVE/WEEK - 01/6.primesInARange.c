#include<stdio.h>

int prime(int num){
	int count = 0;
	int j;
	
	for(j = 2; j <= num/2; j++ ){
		
		if(num % j == 0){
			count++;
		}
	}
	
	if(count == 0){
		return 1;
	}
		
}

int main(){
    int lr , hl, i;
    printf("Enter range: ");
    scanf("%d%d", &lr, &hl);
    
    if(lr < 2){
    	lr = 2;
	}
    
    for(i = lr; i < hl; i++){
    	int abc = prime(i);
    	if(abc == 1){
    		printf("%d  ", i);
		}
	}
	
	return 0;
    

}
