#include<stdio.h>

int main(){
    int n,i;
    int nums[10];
    
    printf("Enter 5 elements in the array:");
    for(i=0;i<5;i++){ scanf("%d",&nums[i]); }
	
	int l,e;
	printf("Enter location and element:");
	scanf("%d%d",&l,&e);
	
	for(i = 5; i  > l; i--){
		nums[i] = nums[i - 1];
	}
	
    nums[l]=e;
    
    printf("Updated array: ");
    for(i=0;i<n;i++){ printf("%d\t",nums[i]); }
}
