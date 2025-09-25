#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i,a,b) for(int i=a; i<=b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; --i)
#define getbit(mask,i) (1&(mask>>i))
#define isz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define pii pair<int,int>
using namespace std;
const int maxN = 1e6 + 7;
const ll inf = 1e9 + 7;
const ll moreinf = 1e15 + 7;
const ll mod = (1ll<<31) - 1;
const ll base = 31;
const int sz = 710;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l ,ll r){
    assert(l<=r);
    return uniform_int_distribution<ll>(l,r)(rng);
}

string NAME = "code";

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num_test = 100;
    rep(TEST,1,num_test){
        ofstream inp;
        inp.open(NAME + ".inp");
        //
        //
        inp.close();
        system((NAME + ".exe").c_str()); 
        system((NAME + "_trau.exe").c_str());
        if(system( ("fc " + NAME + ".out " + NAME + "_trau.out").c_str() )==1){
            cout << "FAILED";
            return 0;
        }
        cout << "PASSED" << endl;
    }
    return 0;
}
