#include<stdio.h>

int main(){
	int num;
	int rev = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	int numcopy = num;
	
	while(num != 0){
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	
	if(numcopy == rev){ 
		printf("palindrome!");
	}else{
		printf("not a palinrome!");
	}
	
	return 0;
}
