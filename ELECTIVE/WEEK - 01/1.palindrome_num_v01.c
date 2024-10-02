#include <stdlib.h>
#include <stdio.h>

int main(){
	
	int num;
	printf("Enter a num: ");
	scanf("%d", &num);
	
	int num_copy = num;
	
	int rev = 0;
	while(num != 0){
		int rem = num % 10;
		rev = (rev * 10) + rem;
		num /= 10;
	}
	
	if(rev == num_copy){
		printf("%d is a palindrome", num_copy);
	}else{
		printf("%d is not a palindrome", num_copy);
	}
	
	return 0;
}

