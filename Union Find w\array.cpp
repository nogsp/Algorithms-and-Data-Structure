#include <iostream>
#include <vector>
#define TIPE int
#define pb push_back
using namespace std;
 
void create_union(int n, vector<TIPE>&pai, vector<TIPE>&peso){
   for(int i=0;i<=n;i++){
       pai.pb(i);
   }  
    peso.resize(n);
   
}
 
TIPE find(int x, vector<TIPE>&pai){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x], pai);
}
 
void join(int x, int y, vector<TIPE>&pai, vector<TIPE>&peso){
    x = find(x, pai);
    y = find(y, pai);
    if(x==y) return;
    if(peso[x]<peso[y]){
        pai[x] = y;
    }
    else if(peso[x]>peso[y]){
        pai[y] = x;
    }
    else{
        pai[x] = y;
        peso[y]++;
    }
 
}
 
int main(){
    vector<TIPE> pai, peso;
    return 0;
}
