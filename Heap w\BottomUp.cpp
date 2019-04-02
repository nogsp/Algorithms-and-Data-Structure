#include <bits/stdc++.h>

using namespace std;

void bottom_up(int vet[], int n){
    int i;
    for(i=n/2;i>=1;i--){
        int k = i;
        int j;
        int v = vet[k];
        bool heap=false;
        while(!heap && (2*k)<=n){
            j = 2*k;
            if(j<n && vet[j]<vet[j+1]){
                j++;
            }
            if(v>=vet[j]){
                heap = true;
            }
            else{
                vet[k] = vet[j];
                 k = j;
            }
        }
        vet[k] = v;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, array[100000];
	cin >> n;
	int i;
	for(i=1;i<=n;i++){
		cin >> array[i];
	}
	bottom_up(array, n);
	for(i=1;i<=n;i++){
		cout << array[i] << " ";
	}
	cout << endl;
    return 0;
}                                 
