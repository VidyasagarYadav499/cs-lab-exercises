#include <stdio.h>

int get_hcf(int x, int y){
	if(y == 0){
		return x;
	}
	
	return(y, x % y);
}

int main(){
	int num1, num2;
	
	printf("Enter two positive numbers: ");
	scanf("%d%d", &num1, &num2);
	
	int hcf = get_hcf(num1, num2);
	int lcm = (num1 * num2) /hcf;
	
	printf("lcm = %d, hcf = %d", lcm, hcf);

	return 0;
}
