#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define rep(i,a,b) for(int i=a; i<=b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; --i)
#define getbit(mask,i) (1ll&(mask>>i))
#define all(v) (v).begin(),(v).end()
#define isz(v) (int)(v).size()
#define pii pair<int,int>
using namespace std;
const ll inf = 1e9 + 7;
const ll moreinf = 1e18 + 7;
const ll base = 256;
const int sz = 300;

const ll MOD[] = {(1ll<<31)-1, (ll)1e9 +22071997};
 
inline ll CELL(ll a, ll b){return a/b + (a%b>0);}
inline ll FLOOR(ll a, ll b){return a/b - (a%b<0);}

template<typename T> inline void setmin(T &a, const T &b){if(a > b) a = b;}
template<typename T> inline void setmax(T &a, const T &b){if(a < b) a = b;}
 
const int maxN = 2e5+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

struct Node{
    Node *l, *r;
    ll lazy, sum_range, sum_ans;
    Node(){
        l = r = nullptr;
        lazy = sum_range = sum_ans = 0;
    }
};

Node *st;

void apply(Node *node, int l, int r, int x){
    node->sum_ans += 1ll * 2 * node->sum_range * x % inf + 1ll * (r-l+1)*x%inf*x%inf;
    node->sum_ans %= inf;
    node->sum_range += 1ll * (r-l+1)*x%inf;
    node->sum_range %= inf;
    (node->lazy += x)%=inf;
}

void push(int l, int r, Node *node){
    if(node->lazy){
        int mid = l + r >> 1;
        apply(node->l,l,mid,node->lazy);
        apply(node->r,mid+1,r,node->lazy);
        node->lazy = 0;
    }
}

void update(Node *node, int u, int v, int x, int l = 1, int r = 1e9){
    if(v<l || r<u) return;
    if(u<=l && r<=v){
        apply(node,l,r,x);
        return;
    }
    int mid = l + r >> 1;
    if(node->l==nullptr) node->l = new Node();
    if(node->r==nullptr) node->r = new Node();
    push(l,r,node);
    update(node->l,u,v,x,l,mid);
    update(node->r,u,v,x,mid+1,r);
    node->sum_range = (node->l->sum_range + node->r->sum_range)%inf;
    node->sum_ans = (node->l->sum_ans + node->r->sum_ans)%inf;
}

ll get(Node *node, int u, int v, int l = 1, int r = 1e9){
    if(v<l || r<u) return 0;
    // cout << l << " " << r << endl;
    if(u<=l && r<=v) return node->sum_ans;
    int mid = l + r >> 1;
    if(node->l==nullptr) node->l = new Node();
    if(node->r==nullptr) node->r = new Node();
    push(l,r,node);
    ll ans = 0;
    if(node->l) (ans += get(node->l,u,v,l,mid))%=inf;
    if(node->r) (ans += get(node->r,u,v,mid+1,r))%=inf;
    return ans;
}

signed main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    if(fopen("code.inp","r")){
        freopen("code.inp","r",stdin);
        freopen("code.out","w",stdout);
    }
    if(fopen("island.in","r")){
        freopen("island.in","r",stdin);
        freopen("island.out","w",stdout);
    }

    st = new Node();

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type){
            int l,r,val; cin >> l >> r >> val;
            update(st,l,r,val);
        }else{
            int l,r; cin >> l >> r;
            cout << get(st,l,r) << endl;
        }
    }

    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
