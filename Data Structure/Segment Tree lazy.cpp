/*
 
               .;;;;:
              :::::::;
              ;::::::;
               :;;;;.
                 ;:::;
                 ;:::::;;                                                           ;;;
                ::::::::::;;                                                       ;:::
                ;:::::::::::;;:                                                  .;;:::
               .;::::::::::::::;;.                  .:.::::                   ;;;:::;;;
               :;:::::::::::::::::;;.            :. .::::....:            :;;::::::::;
               ;::::::::::....:::::::;;;;;;;;;;: .:...  ....:..:      .;;::::::::::::;
              :;::::::::........::::::::::::::. :. .. ...  .  .....;;;:::::::::::::::;
              ;::::::::..........::::::::::::: ....   .....   .....:::::::::::::::::;:
             .;:::::::...........::::::::::::  :.. ...    ...........:::::::::::::::;.
            ......................::::::::::: ..   ....    ..............:::::::::::;
            ..........:::.......:::::::::::::. . ..    ....    ............:::::::::;
            ..........::::::::::::::::.......: .:....    ...    ........ .:  ::::::;;
              ........:::::::::::::...........:. ::. ....   ....    ....   .: .::::;:
              .......:::::::::::::..............::. .::..     ..    ....    .:..:::;:
               ...::::::::::::::::..:::....::....::::.   :....   ....   ....  : ::.
               ;::::::::::::::::::..::.....:::...::::::::. .:.    ...   ..... .. .
              :;::::::::;;   .;:::::............:::::::::::  :....    ... ..  :.:
              ;:::::::;.        ;;:::.......:::::;;;;..;;;::. :....   ....   ...:
              ;:::::;:            .;;::::::;;;;.           ;;:...   ..  .. .:. .
              ;::::::                :;;:                   .;:: ....... .:. :
              ;::::;     ;.                                   ;;::  :::.. .:;:
              ;;::;:    :;;;;;;                               .;::::::::::::;
               ;::;:    .;;;;;;;                               :;::::::::::::
               .;:;:    .::;;;;;                               .;::::::::::;.
                .;;;.....;;;;;;       ...                      .;:::::::::;.
                  ;;:....             .:.          ;;;;;;      :;::::::::;.
                   :;:.........                        .....   ;:::::::;:
                    .............       ..             ...... :;:::::;:
                ................... .;;;.  .:;.              ;;:::;;:
               ..  .......        ..:;;:;;      ;:         :;::;;:
               ;.:::..   ..........:;;;;;        .;...:.;;;;;.               .
               :;:;.................;.;:;         ;:::::::::             ;;;:::
                  .;....:........;; ;;:::;        .:::::;;:::;.:::.   .;:::::::
                  .:...:; ;..:.:.:::.:;;;:::.       :;:: :   ..:.:.     .;:::::
                  ::.........;;+:....:; .:..::        .::..;           ;::;:;;:
                  ;:...........::;;;;;:  .:: .;      ::..:. :.       ;:::;.  :.
                  ::::::...;.        ::::      ..;;;.        ;.   ;;:::;.
                  .. ::.;:.;:     .::;;;                      ;;;:::;;.
                ::.;   :;;;;:::........;                      ;:::;:
               .;...::::........;:.....:;                     ;:
*/

 
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
const ll moreinf = 1e16 + 7;
const ll base = 256;
const int sz = 300;

const ll MOD[] = {(1ll<<31)-1, (ll)1e9 +22071997};
 
inline ll CELL(ll a, ll b){return a/b + (a%b>0);}
inline ll FLOOR(ll a, ll b){return a/b - (a%b<0);}

template<typename T> inline void setmin(T &a, const T &b){if(a > b) a = b;}
template<typename T> inline void setmax(T &a, const T &b){if(a < b) a = b;}
 
const int maxN = 1e5+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

int n,q,a[maxN];

struct SegmentTree{
    vector<ll> st,lazy;

    void init(int n){
        st.assign(4*n+2,0);
        lazy.assign(4*n+2,0);
    }

    void assign(int id, int l, int r, ll val){
        st[id] += val;
        lazy[id] += val;
    }
    void push(int id, int l, int r){
        int mid = l + r >> 1;
        assign(id<<1,l,mid,lazy[id]);
        assign(id<<1|1,mid+1,r,lazy[id]);
        lazy[id] = 0;
    }
    void update(int u, int v, int x, int l, int r, int id){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            assign(id,l,r,x);
            return;
        }
        int mid = l + r >> 1;
        push(id,l,r);
        update(u,v,x,l,mid,id<<1);
        update(u,v,x,mid+1,r,id<<1|1);
        st[id] = max(st[id<<1],st[id<<1|1]);
    }
    ll get(int u, int v, int l, int r, int id){
        if(v<l || r<u) return -moreinf;
        if(u<=l && r<=v) return st[id];
        int mid = l + r >> 1;
        push(id,l,r);
        return max(get(u,v,l,mid,id<<1), get(u,v,mid+1,r,id<<1|1));
    }
    void update(int u, int v, int x){
        update(u,v,x,1,n,1);
    }
    ll get(int u, int v){
        return get(u,v,1,n,1);
    }
}st;

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

    cin >> n;
    rep(i,1,n) cin >> a[i];

    st.init(n);

    int q; cin >> q;    

    rep(i,1,n) st.update(i,i,a[i]);

    while(q--){
        int type; cin >> type;
        if(type==2){
            int l,r; cin >>l >> r;
            cout << st.get(l,r) << endl;
        }else{
            int l,r,x; cin >> l >> r >> x;
            st.update(l,r,x);
        }
    }

    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

/*
a[i] - x
a[i] + x
*/
