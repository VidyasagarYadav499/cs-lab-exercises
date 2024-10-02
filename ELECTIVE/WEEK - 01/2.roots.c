#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c; // Coefficients.
	
	printf("Enter a, b, c (from ax^2 + bx + c = 0); ");
	scanf("%d%d%d", &a, &b, &c);
	
	double D = b * b- 4 * a * c; // Discriminant.
	
	if(D < 0){
		printf("No real roots!");
		return 0;
	}
	
	double x1 = (-b + sqrt(D))/2 * a;
	double x2 = (-b - sqrt(D))/2 * a;
	
	printf("roots : %.2f, %.2f", x1, x2);

	return 0;
}
