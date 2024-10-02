#include <stdlib.h>
#include <stdio.h>

int main(){
	int arr1[] = {1, 2, 6, 8, 12};
	int arr2[] = {3, 4, 5, 9, 11, 13, 22};
	int len1 = 5;
	int len2 = 7;
	int arr3[len1 + len2];
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while(i < len1 && j < len2){
		if(arr1[i] < arr2[j]){
			arr3[k] = arr1[i];
			i++;
			k++;
		}
		else if(arr1[i] == arr2[j]){
			arr3[k] = arr1[i];
			i++;
			k++;
		}else{
			arr3[k] = arr2[j];
			j++;
			k++;
		}
	}
	
	while(i < len1){
		arr3[k] = arr1[i];
		i++;
		k++;
	}
	
	while(j < len2){
		arr3[k] = arr2[j];
		j++;
		k++;
	}
	
	for(int i = 0; i < len1 + len2; i++) {
		printf("%d  ", arr3[i]);
	}

	return 0;
}
