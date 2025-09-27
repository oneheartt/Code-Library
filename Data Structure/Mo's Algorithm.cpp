struct q_data{
    int l,r,id;
    void input(int i){
        id = i;
        cin >> l >> r;
    }
    bool operator < (const q_data &other) const{
        if(l/sz == other.l/sz) return r < other.r;
        return l/sz < other.l/sz;
    }
}query[maxN];

int L = 1, R = 0;
rep(i,1,q){
    int l = query[i].l, r = query[i].r, id = query[i].id;
    while(L < l) del(L++);
    while(L > l) add(--L);
    while(R < r) add(++R);
    while(R > r) del(R--);
    ans[id] = ok;
}
