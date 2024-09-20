#include <stdio.h>
#include <math.h>

int main(){
    int p, r, t;
    printf("Enter values of P, R, T: ");
    scanf("%d%d%d",&p,&r,&t);
    
    double si = (p * r * t) / 100;
	double ci = p * pow(1 + r / 100.0, t) - p;
	printf("SI and CI are: %f and %f", si, ci);
	
	return 0;
}

