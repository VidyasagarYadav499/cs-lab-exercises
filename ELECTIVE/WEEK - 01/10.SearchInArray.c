#include<stdio.h>
int main(){
    int n,e,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int nums[n];
    
    printf("Enter elements of array:");
    for(i=0;i<n;i++){ scanf("%d",&nums[i]); }
	
	printf("Enter element to search:");
	scanf("%d",&e);
	
    for(i=0;i<n;i++){ 
		if(e==nums[i]){ printf("Element found at %d",i); }
    }
    
    return 0;
}
