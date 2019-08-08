#include <bits/stdc++.h>

using namespace std;
int *segt;
void build(int vet[], int index, int tl, int tr){
	if(tl == tr){
		segt[index] = vet[tl];
	}
	else{
		int tm = (tl + tr) / 2;
		build(vet, index*2, tl, tm);
		build(vet, index*2+1, tm+1, tr);
		segt[index] = segt[index*2] + segt[index*2+1];
	}
}

int sum(int index, int tl, int tr, int l, int r){
	if(l<=tl && r>=tr) return segt[index];
	if(tr<l || tl>r) return 0;
	int tm = (tr + tl) / 2;
	return sum(index*2, tl, tm, l, r)
		   + sum(index*2+1, tm+1, tr, l, r);
}

void update(int index, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        segt[index] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(index*2, tl, tm, pos, new_val);
        else
            update(index*2+1, tm+1, tr, pos, new_val);
        segt[index] = segt[index*2] + segt[index*2+1];
    }
}

int main(){
	int n, m;
	scanf("%d", &n);
	int *vet = new int[n];
	segt = new int[n*4];
	for(int i=0;i<n;i++){
		scanf("%d", &vet[i]);
	}
	build(vet, 1, 0, n-1);
	scanf("%d", &m);
	while(m--){
		char c;
		int a, b;
		scanf(" %c", &c);
		scanf("%d %d", &a, &b);
		if(c=='Q'){
			printf("%d", sum(0,1,n-1,a,b));
			printf("%d\n");
		} else {
			update(1, 0, n-1, a, b)
		}
	}
}
