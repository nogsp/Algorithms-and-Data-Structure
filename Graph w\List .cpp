#include<bits/stdc++.h>
#define pb push_back
#define new_vet vector<vector<pair<int,int>>>
using namespace std;

int dist[(int)1e4];
 
struct Grafo {
    int numEdge;
    vector<int> mark, grau;
    new_vet lista;
};
 
void create_grafo(Grafo &grafo, int n){
    grafo.lista.resize(n);
    grafo.numEdge=0;
    grafo.mark.resize(n);
    grafo.grau.resize(n);
}
 
int v_number(Grafo &grafo){
    return grafo.mark.size();
}
 
int e_number(Grafo &grafo){
    return grafo.numEdge;
}
 
int first(Grafo &grafo, int a){
    return grafo.lista[a][0].first;
}
 
int next(Grafo &grafo, int a, int w){
    int i;
    int v_size=grafo.lista[a].size();
    for(i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==w){
            i++;
            break;
        }
    }
    if(i>=v_size){
        cout << "Nao existe" << endl;
        return -1;
    }
    return grafo.lista[a][i].first;    
}
 
void setEdge(Grafo& grafo, int a, int b, int p){
    int v_size=grafo.lista[a].size(), i;
    grafo.numEdge++;
    //cout << v_size << endl;
    for( i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
            grafo.lista[a][i].second=p;
            grafo.grau[b]++;
            break;
        }
    }
    if(i<v_size) return;
    grafo.lista[a].pb(make_pair(b, p));
    grafo.grau[b]++;
    sort(grafo.lista[a].begin(), grafo.lista[a].end());
}

void delEdge(Grafo &grafo, int a, int b){
    int v_size=grafo.lista[a].size();
    for(int i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
           grafo.lista[a].erase(grafo.lista[a].begin()+i);
            grafo.numEdge--;
            break;
        }
    }
}
 
bool isEdge(Grafo &grafo, int a, int b){
    int v_size=grafo.lista[a].size();
    for(int i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
            return true;
        }
    }
    return false;
}
 
int weight(Grafo &grafo, int a, int b){
    int v_size=grafo.lista[a].size();
    for(int i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
            return grafo.lista[a][i].second;
        }
    }
    return 0;
}
 
void setMark(Grafo &grafo, int a, int val){
    grafo.mark[a]=val;
}
 
int getMark(Grafo &grafo, int a){
    return grafo.mark[a];
}

void print_lista(Grafo& grafo, int n){
    int i, j;
    for(i=0;i<n;i++){
        int str=grafo.lista[i].size();
        cout << i << "   ";
        for(j=0;j<str;j++){
            cout << grafo.lista[i][j].first << " ";
        }
        if(j==0)cout << "Lista vazia";
        cout << endl;
        cout << "    ";
        for(j=0;j<str;j++){
            cout << grafo.lista[i][j].second << " ";
        }
        cout << endl; 
    }
}

void topoSort(Grafo& grafo){
    vector<int> lista;
    int v_size=v_number(grafo);
    for(int i=0;i<v_size;i++) if(grafo.grau[i]==0) lista.pb(i);
    int ini=0;
    while(ini<lista.size()){
        int atual= lista[ini];
        ini++;
        for(int i=0;i<grafo.lista[atual].size();i++){
            int v=grafo.lista[atual][i].first;
            grafo.grau[v]--;
            if(grafo.grau[v]==0) lista.push_back(v);
        }
    }
    if(lista.size()<v_number(grafo)) cout << "Deu merda" << endl;
    else{
        for(int i=0;i<v_size;i++){
            cout << lista[i] << " ";
        }
        cout << endl;
    }
}

void dijkstra(Grafo& grafo, int origem){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    memset(dist,0x3f, sizeof(dist));
    dist[origem]=0;
    heap.push({0,origem});
    while(!heap.empty()){
        pair<int,int> rola = heap.top();
        heap.pop();
        int p = rola.first;
        int v = rola.second;
        if(p>dist[v]){
            continue;
        }
        for(auto& it:grafo.lista[v]){
            if(dist[it.first]>p+it.second){
                dist[it.first] = p+it.second;
                heap.push({dist[it.first],it.first});
            }
        }
    }
    
    
}
   
int main(void){
    
    int i, n, e, a, b, p, c;
    int casos;
    cin >> casos;
    while(casos--){
        Grafo grafo;
        cin >> n >> e;
        create_grafo(grafo, n);
        while(e--){
            cin >> a >> b >> c;
            setEdge(grafo, --a, --b, c);
        }
        cin >> a >> b;
        dijkstra(grafo, --a);
        (dist[--b]==0x3f3f3f3f)? cout << "NO" << endl : cout << dist[b] << endl;
    }    
    return 0;
}
