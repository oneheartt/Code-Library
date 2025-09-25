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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//Naive Solution as follows...
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
 
const int maxN = 2e5+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

int n,q,a[maxN];

vector<int> st[4*maxN + 2]; 

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c;
    int l = 0, r = 0;
    while(l < isz(a) && r < isz(b)){
        if(a[l] < b[r]) c.push_back(a[l++]);
        else c.push_back(b[r++]);
    }
    while(l < isz(a)) c.push_back(a[l++]);
    while(r < isz(b)) c.push_back(b[r++]);
    return c;
}

void build(int l = 1, int r = n, int id = 1){
    if(l==r){
        st[id].push_back(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    st[id] = merge(st[id<<1], st[id<<1|1]);
}

int get(int u, int v, int a, int b, int l = 1, int r = n, int id = 1){
    if(v<l || r<u) return 0;
    if(u<=l && r<=v){
        int ans = 0;
        if(st[id][0]<=b){
            ans += upper_bound(all(st[id]),b) - begin(st[id]);
        }
        if(st[id][0]<=a-1){
            ans -= upper_bound(all(st[id]),a-1) - begin(st[id]);
        }
        return ans;
    } 
    int mid = l + r >> 1;
    return get(u,v,a,b,l,mid,id<<1) + get(u,v,a,b,mid+1,r,id<<1|1);
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

    cin >> n >> q;
    rep(i,1,n) cin >> a[i];

    build();

    while(q--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        cout << get(a,b,c,d) << endl;
    }

    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
