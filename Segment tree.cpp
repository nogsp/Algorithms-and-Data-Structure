#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define ll long long
#define inf 1000001 //DEPENDS ON THE PROBLEM

using namespace std;

class segTreeSum{
	ll *segt;
	ll *vet;
public:
	segTreeSum(ll n){
		this->segt = new ll[n*4];
	}
	segTreeSum(ll n, ll vet[]){
		this->segt = new ll[n*4];
		this->vet = vet;
		build(1,0,n-1);
	}
	void addArray(ll vet[]){
		this->vet = vet;
	}	
	void build(int index, int tl, int tr){
		if(tl == tr){
			segt[index] = vet[tl];
		}
		else{
			int tm = (tl + tr) / 2;
			build(index*2, tl, tm);
			build(index*2+1, tm+1, tr);
			segt[index] = segt[index*2] + segt[index*2+1];
		}
	}

	int query(int index, int tl, int tr, int l, int r){
		if(l<=tl && r>=tr) return segt[index];
		if(tr<l || tl>r) return 0;
		int tm = (tr + tl) / 2;
		return query(index*2, tl, tm, l, r)
		   	+ query(index*2+1, tm+1, tr, l, r);
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
};

class segTreeMin{
	ll *segt;
	ll *vet;
public:
	segTreeMin(ll n){
		this->segt = new ll[n*4];
	}
	segTreeMin(ll n, ll vet[]){
		this->segt = new ll[n*4];
		this->vet = vet;
		build(1,0,n-1);
	}
	void addArray(ll vet[]){
		this->vet = vet;
	}	
	void build(int index, int tl, int tr){
		if(tl == tr){
			segt[index] = vet[tl];
		}
		else{
			int tm = (tl + tr) / 2;
			build(index*2, tl, tm);
			build(index*2+1, tm+1, tr);
			segt[index] = min(segt[index*2], segt[index*2+1]);
		}
	}

	int query(int index, int tl, int tr, int l, int r){
		if(l<=tl && r>=tr) return segt[index];
		if(tr<l || tl>r) return inf;
		int tm = (tr + tl) / 2;
		return min(query(index*2, tl, tm, l, r)
		   	,query(index*2+1, tm+1, tr, l, r));
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
        		segt[index] = min(segt[index*2], segt[index*2+1]);
    		}
	}	
};

int main(){
	ll n, vet[101010];
	scanf("%lld", &n);
	for(ll i=0;i<n;i++){
		scanf("%lld",&vet[i]);
	}
	segTreeSum *segtS = new segTreeSum(n, vet);
	segTreeMin *segtM = new segTreeMin(n, vet);
	ll q;
	scanf("%lld", &q);
	while(q--){
		char op;
		int a, b;
		scanf(" %c %d %d", &op, &a, &b);
		if(op=='Q' || op=='q'){
			ll v1 = segtS->query(1,0,n-1,a,b);
			ll v2 = segtM->query(1,0,n-1,a,b);
			printf("%lld %lld\n",v1, v2);
		}
		else{
			segtS->update(1,0,n-1, a, b);
			segtM->update(1,0,n-1, a, b);
		}
	}
}

