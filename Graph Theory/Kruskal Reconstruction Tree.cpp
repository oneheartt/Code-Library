void buildkrt(){
    vector<array<int,3>> vec;
    rep(i,1,n-1){
        vec.push_back(edge[i]);
    }
    sort(all(vec), [](array<int,3> a, array<int,3> b){
        return a[2] > b[2];
    });
    DSU g; g.init(2*n);
    for(array<int,3> p:vec){
        int u = p[0], v = p[1], w = p[2];
        if(!g.sameset(u,v)){
            ++n;
            int pu = g.find(u), pv = g.find(v);
            // cout << n << "->" << pu << endl;
            // cout << n << "->" << pv << endl;
            adj[n].push_back(pu);
            adj[n].push_back(pv);
            g.unite(n,pu);
            g.unite(n,pv);
            val[n] = w;
        }
    }
}
