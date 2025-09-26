int h[maxN], bJump[21][maxN], subsize[maxN] ,val[maxN];
void dfs(int u, int p){
    rep(k,1,19) bJump[k][u] = bJump[k-1][bJump[k-1][u]];
    subsize[u]++;
    for(int v:adj[u]){
        if(v==p) continue;
        h[v] = h[u] + 1;
        bJump[0][v] = u;
        dfs(v,u);
        subsize[u] += subsize[v];
    }
}

int LCA(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    rep(k,0,19) if(getbit(delta,k)) u = bJump[k][u];
    if(v==u) return u;
    rev(k,19,0){
        if(bJump[k][u] != bJump[k][v]){
            u = bJump[k][u];
            v = bJump[k][v];
        }
    }
    return bJump[0][u];
}
