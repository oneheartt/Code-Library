struct Node{
    Node *l, *r;
    int cnt;
    Node(int x){
        l = r = nullptr;
        cnt = x;
    }
    Node(Node *l, Node *r){
        cnt = 0;
        this->l = l, this->r = r;
        if(l) cnt += l->cnt;
        if(r) cnt += r->cnt;
    }
    Node(Node *node){
        this->l = node->l;
        this->r = node->r;
        this->cnt = node->cnt;
    }
};

Node *st[maxN];

Node *build(int l = 1, int r = n){
    if(l==r) return new Node(0); 
    int mid = l + r >> 1;
    return new Node(build(l,mid), build(mid+1,r));
}

Node *update(Node *cur, int pos, int x, int l = 1, int r = n){
    if(l==r) return new Node(x);
    int mid = l + r >> 1;
    if(pos <= mid) return new Node(update(cur->l,pos,x,l,mid),cur->r);
    return new Node(cur->l,update(cur->r,pos,x,mid+1,r));
}

int get(Node *cur, int u, int v, int l = 1, int r= n){
    if(v<l || r<u) return 0;
    if(u <= l && r <= v) return cur->cnt;
    int mid = l + r >> 1;
    return get(cur->l,u,v,l,mid) + get(cur->r,u,v,mid+1,r);
}
