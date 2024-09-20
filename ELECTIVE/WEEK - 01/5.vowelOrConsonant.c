#include<stdio.h>
#include<ctype.h>

int main(){
	char i;
	printf("Enter an English Alphabet: ");
	scanf("%c", &i);
	i = tolower(i);

	if(isdigit(i)){
		printf("Invalid input!");
		return 0;
	}
	
	
	if(i == 'a' || i == 'e'|| i == 'i' || i == 'o' || i == 'u'){
		printf("Vowel!");
	}else{
		printf("Consonant!");
	}
	return 0;
}
