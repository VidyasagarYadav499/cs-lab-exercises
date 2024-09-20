#include<stdio.h>
#include<ctype.h>

int main(){
	int year;
	printf("Enter a year: ");
	scanf("%d", &year);
	
	if(year % 4 == 0){
		printf("Leap year!");
	}else{
		printf("Not a Leap year!");
	}
	
	return 0;
}
