struct SegmentTree{
    int n;
    struct Node{
        ll sum, Lmul, Lsum;
        Node(){
            sum = Lsum = 0;
            Lmul = 1;
        }
        Node operator + (const Node &other) const{
            Node final;
            final.sum = addmod(sum,other.sum);
            return final;
        }
    };
    vector<Node> st;
    void init(int n){
        this->n = n;
        st.assign(4*n+2,Node());
    }

    void assign(int id, int l, int r, ll m, ll a){
        st[id].sum = addmod(mulmod(st[id].sum,m),mulmod(a,(r-l+1)));
        st[id].Lmul = mulmod(st[id].Lmul,m);
        st[id].Lsum = addmod(mulmod(st[id].Lsum,m),a);
    }

    void push(int id, int l, int r){
        int mid = l + r >> 1;
        assign(id<<1,l,mid,st[id].Lmul, st[id].Lsum);
        assign(id<<1|1,mid+1,r,st[id].Lmul, st[id].Lsum);
        st[id].Lmul = 1, st[id].Lsum = 0;
    }

    void update(int u, int v, ll m, ll a, int l, int r, int id){
        if(v<l || r <u) return;
        if(u <= l && r <= v){
            assign(id,l,r,m,a);
            return;
        }
        int mid = l + r >> 1;
        push(id,l,r);
        update(u,v,m,a,l,mid,id<<1);
        update(u,v,m,a,mid+1,r,id<<1|1);
        st[id] = st[id<<1] + st[id<<1|1];
    }

    ll get(int u, int v, int l, int r, int id){
        if(v<l || r <u) return 0;
        if(u <= l && r <= v) return st[id].sum;
        int mid = l + r >> 1;
        push(id,l,r);
        return addmod(get(u,v,l,mid,id<<1),get(u,v,mid+1,r,id<<1|1));
    }
    void update(int u, int v, ll m, ll a){
        update(u,v,m,a,1,n,1);
    }
    ll get(int u, int v){
        return get(u,v,1,n,1);
    }
}st;
