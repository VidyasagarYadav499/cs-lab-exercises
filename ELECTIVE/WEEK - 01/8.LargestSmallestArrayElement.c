#include<stdio.h>
int main(){
    int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int nums[n];
    
    printf("Enter elements of array:");
    for(i=0;i<n;i++){ scanf("%d",&nums[i]); }
	
	int l=nums[0],s=nums[0];
	for(i=0;i<n;i++){
		if(l<nums[i]){ l=nums[i]; }
		if(s>nums[i]){ s=nums[i]; }
	}
	
	printf("Largest and smallest element are: %d and %d",l,s);
}
