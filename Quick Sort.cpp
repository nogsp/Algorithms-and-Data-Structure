#include<iostream>
using namespace std;

int hoare_partition(int a[], int ini, int fin){
	int pivo, l, r, temp;
	l = ini;
	r = fin-1;
	pivo = a[ini];
	while(l < r){
		while(a[l] <= pivo){
			l++;
		}
		while(a[r]>pivo){
			r--;
		}
		if(l<r){
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	a[ini] = a[r];
	a[r] = pivo;
	return r;
}

void quick_sort(int a[], int start, int end){
	int q; 
	if(end>start){
		q = hoare_partition(a, start, end);
		quick_sort(a,start, q);
		quick_sort(a, q+1, end);
	}	
}
int main() {
	ios::sync_with_stdio(0);
    	cin.tie(0);
    
	int vet[100000], vetn=0;
	cin >> vetn;
	int i;
	for(i=0;i<vetn;i++){
		cin >> vet[i];
	}
	
	quick_sort(vet, 0, vetn);
	
	for(i=0;i<vetn;i++){
		cout << vet[i] << " ";
	}
	return 0;
}
