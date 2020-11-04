#include <stdio.h>
#include <stdlib.h>

int binarySearch(int A[], int k, int n){
	int l = 0, r = n - 1;
	int resp = -1;
	while(l <= r){
		int m = (l + r) >> 1;
		if(k == A[m]){
			resp = m;
			r = m - 1;
		}
		else if(k < A[m]){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	return resp; 
}

int main(){
	int size, queries, i;
	scanf("%d %d", &size, &queries);
	int vet[size], k; 
	for(i = 0; i < size; i++){
		scanf("%d", &vet[i]);
	}
	while(queries--) {
		scanf("%d", &k);
		int pos = binarySearch(vet, k, size);
		printf("%d\n", pos);
	}	
	return 0;
}