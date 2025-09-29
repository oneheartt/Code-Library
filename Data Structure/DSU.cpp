struct DSU{
    vector<int> lab;
    void init(int n){
        lab.assign(n+2,-1);
    }
    int find(int u){
        return lab[u] < 0 ? u : lab[u] = find(lab[u]);
    }
    bool unite(int u,int v){
        u = find(u), v = find(v);
        if(u==v) return 0;
        if(-lab[u] < -lab[v]) swap(u,v);
        lab[u] += lab[v];
        lab[v] = u;
        return 1;
    }
};
