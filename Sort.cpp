#include<iostream>

using namespace std;

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  SELECTION SORT   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void selection_sort(int vet[], int n){
	int i, j, min;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(vet[j]<vet[min]){
				min = j;
			}
		}
		int aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  INSERTION SORT   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void insertion_sort(int vet[],int n){
	int i, j, v;
	for(i=0;i<n;i++){
		v = vet[i];
		j = i-1;
		while(j>=0 && vet[j]>v){
			vet[j+1] = vet[j];
			j = j-1;
		}
		vet[j+1] = v;
	}
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  MERGE SORT  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void merge(int A[], int inicio, int meio, int fim){
	int i=0, j=0, k=0;
	int temp[100000], p1, p2, tam;
	int fim1=0, fim2=0;
	tam = fim-inicio+1;
	p1 = inicio;
	p2=meio+1;
	for(i=0;i<tam;i++){
		if(!fim1 && !fim2){
			if(A[p1]<A[p2]){
				temp[i] = A[p1++];
			}
			else{
				temp[i] = A[p2++];
			}
			if(p1>meio){
				fim1 = 1;
			}
			if(p2>fim){
				fim2 = 1;
			}
		}
		else{
			if(!fim1){
				temp[i] = A[p1++];
			}
			else{
				temp[i] = A[p2++];
			}
		}
	}
	for(j=0,k=inicio;j<tam;j++,k++){
		A[k] = temp[j];
	}
}

void merge_sort(int A[], int inicio, int fim){
	int meio;
	if(inicio<fim){
		meio = (inicio+fim)/2;
		merge_sort(A,inicio,meio);
		merge_sort(A,meio+1,fim);
		merge(A,inicio,meio,fim);
	}
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  QUICK SORT  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
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

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  HEAP SORT  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void bottom_up(int heap[], int n){
    int k,v, i, j;
    bool check;
    for(i=n/2;i>=1;i--){
        k = i;
        check = false;
        v = heap[i];
        while(!check && (2*k)<=n){
            j = 2*k;
            if(j<n && heap[j]<heap[j+1]){
                j++;
            }
            if(v>=heap[j]){
                check = true;
            }
            else{
                heap[k] = heap[j];
                k = j;
            }
        }
        heap[k] = v;
    }
}

void heap_sort(int heap[], int n){
    if(n>1){
        bottom_up(heap, n);
        int aux = heap[n];
        heap[n] = heap[1];
        heap[1] = aux;
        heap_sort(heap, n-1);
    }    
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int main() {
	ios::sync_with_stdio(0);
    	cin.tie(0);
    
	int vet[100000], vetn=0;
	cin >> vetn;
	int i;
	for(i=0;i<vetn;i++){
		cin >> vet[i];
	}
	
	//---(COLOCAR UMA FUNCAO SORT NESSE LUGAR)----//
	
	for(i=0;i<vetn;i++){
		cout << vet[i] << " ";
	}
	return 0;
}
