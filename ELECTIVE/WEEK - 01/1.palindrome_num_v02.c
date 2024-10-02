#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	
	char str[20];
	printf("Enter a num: ");
	scanf("%s", str);
	
	char str_rev[20];
	
	strcpy(str_rev, str);
	strrev(str_rev);
	
	
	
	if(strcmp(str, str_rev) == 0){
		printf("A palindrome");
	}else{
		printf("Not a palindrome");
	}
	
	return 0;
}

