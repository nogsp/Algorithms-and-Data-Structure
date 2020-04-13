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
