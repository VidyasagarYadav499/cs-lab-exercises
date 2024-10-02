#include <stdio.h>

int main(){
	int num1, num2;
	
	printf("Enter two positive numbers: ");
	scanf("%d%d", &num1, &num2);
	
	int hcf;
	
	for(int i = 1; i <= num1; i++){
		if(num1 % i == 0 && num2 % i == 0){
			hcf = i;
		}
	}
	
	int lcm = (num1 * num2) /hcf;
	
	printf("lcm = %d, hcf = %d", lcm, hcf);

	return 0;
}
