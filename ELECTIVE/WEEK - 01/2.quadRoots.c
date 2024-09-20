#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c;
    printf("Enter coefficients of quadratic equation: ");
    scanf("%d%d%d",&a,&b,&c);
    double D=(b*b)-(4*a*c);
    if(D>0){
    	double r1=(-b+sqrt(D))/(2*a),r2=(-b-sqrt(D))/(2*a);
    	printf("Roots are: %f and %f",r1,r2);
	}
	else if(D==0){
		double r1=(-b+sqrt(D))/(2*a),r2=(-b-sqrt(D))/(2*a);
    	printf("Roots are: %f and %f",r1,r2);
	}
	else{
		printf("No real roots exist");
	}
	return 0;
}

