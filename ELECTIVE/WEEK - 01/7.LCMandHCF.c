#include<stdio.h>
int main(){
    int a,b,hcf = 0,lcm,i;
    printf("Enter two positive numbers:");
    scanf("%d%d",&a,&b);
    
    for(i = 1; i <= a; i++){
		if(a % i == 0 && b % i == 0){ hcf=i; }
	}
	
	lcm=(a * b) / hcf;
	printf("LCM and HCF are: %d and %d",lcm,hcf);
	
	return 0;
}
