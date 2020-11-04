#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

ll dist[1010][1010];
ll grafo[1010][1010];

void floyd(ll n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || grafo[i][j]!=0) dist[i][j] = grafo[i][j];
            else dist[i][j] = inf;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[k][j] != inf && dist[i][k] != inf && dist[i][j] > (dist[k][j] + dist[i][k]))
                grafo[i][j] = grafo[k][j] + dist[i][k];
            }
        }
    }
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            grafo[i][j] = 0;
        }
    }
    grafo[0][1] = 10;
    grafo[0][3] = 5;
    grafo[1][3] = 2;
    grafo[1][2] = 1;
    grafo[2][4] = 4;
    grafo[3][2] = 9;
    grafo[3][1] = 3;
    grafo[3][4] = 2;
    grafo[4][2] = 6;
    grafo[4][0] = 7;
    floyd(5);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%lld ", grafo[i][j]);
        }
        printf("\n");
    }
    
}
