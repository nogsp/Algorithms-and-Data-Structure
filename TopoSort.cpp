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
