#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#define NV 0
#define VV 1
using namespace std;
 
struct Grafo{
    int **matrix;
    int **D;
    int numEgde;
    vector<int> mark;
};
 
Grafo create_grafo(int n){
    Grafo grafo;
    grafo.matrix = new int*[n];
    for(int i=0;i<n;i++){
        grafo.matrix[i] = new int[n];
    }
    grafo.numEgde=0;
    grafo.mark.resize(n);
    grafo.D = new int*[n];
    for(int i=0;i<n;i++){
        grafo.D[i] = new int[n];
    }
    return grafo;
}
 
int v_number(Grafo& grafo){
    return grafo.mark.size();
}
 
int e_number(Grafo& grafo){
    return grafo.numEgde;
}
 
int first(Grafo& grafo, int a){
    int v_size = v_number(grafo);
    for(int i=0;i<v_size;i++){
        if(grafo.matrix[a][i]!=0){
            return grafo.matrix[a][i];
        }
    }
    return v_size;
}
 
void setEdge(Grafo& grafo, int a, int b, int p){
    if(p==0) cout << "Tu eh doido rapaz?" << endl;
    if(grafo.matrix[a][b]==0) grafo.numEgde++;
    grafo.matrix[a][b]=p;
    grafo.matrix[b][a]=p;
}
 
void setEdgeD(Grafo& grafo, int a, int b, int p){
    if(p==0) cout << "Tu eh doido rapaz?" << endl;
    if(grafo.matrix[a][b]==0) grafo.numEgde++;
    grafo.matrix[a][b]=p;
}

void delEdge(Grafo& grafo, int a, int b){
    if(grafo.matrix[a][b]!=0) grafo.numEgde--;
    grafo.matrix[a][b]=0;
}
 
bool isEdge(Grafo& grafo, int a, int b){
    if(grafo.matrix[a][b]==0) return false;
    return true;
}
 
int peso(Grafo& grafo, int a, int b){
    return grafo.matrix[a][b];
}
 
void setMark(Grafo& grafo, int a, int val){
    grafo.mark[a]=val;
}
 
int getMark(Grafo& grafo, int a){
    return grafo.mark[a];
}
 
void print_matrix(Grafo grafo){
    int v_size=v_number(grafo);
    cout << "  ";
    for(int i=0;i<v_size;i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0;i<v_size;i++){
        cout << i << " ";
        for(int j=0;j<v_size;j++){
            cout << grafo.matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void print_D(Grafo grafo){
    int v_size=v_number(grafo);
    cout << "  ";
    for(int i=0;i<v_size;i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0;i<v_size;i++){
        cout << i << " ";
        for(int j=0;j<v_size;j++){
            cout << grafo.D[i][j] << " ";
        }
        cout << endl;
    }
}

int cont=0;
 
void DFS(Grafo& grafo, int x){
    int v_size=v_number(grafo);
    for(int i=0;i<v_size;i++){
        int v=grafo.matrix[x][i];
        if(v!=0 && grafo.mark[i]==NV){
            setMark(grafo, i, VV);
            DFS(grafo,i);
        }
    }
}
 
void BFS(Grafo& grafo, int x){
    queue<int> fila;
    fila.push(x);
    setMark(grafo, x, VV);
    int i, atual=0, v_size=v_number(grafo);
    while(!fila.empty()){
        int v=fila.front();
        fila.pop();
        for(i=0;i<v_size;i++){
            int u=grafo.matrix[v][i];
            if(u!=0&&grafo.mark[i]==NV){
                grafo.mark[i]=VV;
                fila.push(i);
            }
        }
    }
}
 
void graphTransverse(Grafo& grafo){
    int v_size = v_number(grafo);
    for(int i=0;i<v_size;i++) setMark(grafo, i, NV);
    for(int i=0;i<v_size;i++){
        if(getMark(grafo, i)==NV){
            cont++;
            DFS(grafo, i);    
        } 
    }
}

void floyd(Grafo& grafo){
    int v_size = v_number(grafo);
    for(int i=0;i<v_size;i++){
        for(int j=0;j<v_size;j++){
            if(i!=j && grafo.matrix[i][j]==0) grafo.D[i][j]=INT_MAX;
            else grafo.D[i][j]=grafo.matrix[i][j];
        }
    }     
    for(int k=0;k<v_size;k++){
        for(int i=0;i<v_size;i++){
            for(int j=0;j<v_size;j++){
                if(grafo.D[i][k]!=INT_MAX and grafo.D[k][j]!=INT_MAX
                and grafo.D[i][j]>grafo.D[i][k]+grafo.D[k][j])
                grafo.D[i][j] = grafo.D[i][k]+grafo.D[k][j];    
            }
        }
    }
}
 
int main(void){
    Grafo grafo;
    int i, n, e, a, b, p;
    cout << "Digite o numero de vertices: ";
    cin >> n;
    cout << "Digite o numero de arestas: ";
    cin >> e;
    grafo = create_grafo(n);
    while(e--){
        cout << "Digite a aresta e o seu peso: ";
        cin >> a >> b >> p;
        setEdge(grafo, a, b, p);
    }
    cout << "Numero de arestas: " << e_number(grafo) << endl;
    cout << "Numero de vertices: " << v_number(grafo) << endl;
    print_matrix(grafo);
    floyd(grafo);
    cout << cont << endl;
    print_D(grafo);
    cout << cont << endl;
 
    return 0;
}


/*Digite o numero de vertices: 7
Digite o numero de arestas: 11
Digite a aresta e o seu peso: 0 1 7
Digite a aresta e o seu peso: 1 2 8
Digite a aresta e o seu peso: 0 3 5
Digite a aresta e o seu peso: 1 3 9
Digite a aresta e o seu peso: 1 4 7
Digite a aresta e o seu peso: 2 4 5
Digite a aresta e o seu peso: 3 4 15
Digite a aresta e o seu peso: 3 5 6
Digite a aresta e o seu peso: 4 5 8
Digite a aresta e o seu peso: 5 6 11
Digite a aresta e o seu peso: 6 4 9*/

