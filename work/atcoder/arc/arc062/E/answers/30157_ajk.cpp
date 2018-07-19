#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int,int>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

typedef pair<pii,pii> C;

C norm(C c) {
    return min(min(C{{c.x.y, c.y.x}, {c.y.y, c.x.x}}, C{{c.y.y,c.x.x},{c.x.y,c.y.x}}), min(c, {c.y,c.x}));
}

int get(const C&c, int i) {
    switch((i+4)%4) {
        case 0: return c.x.x;
        case 1: return c.x.y;
        case 2: return c.y.x;
        case 3: return c.y.y;
    }
}

int rot(const C&c) {
    if (c.x == c.y) {
        if (c.x.x == c.x.y) return 4;
        else return 2;
    } else return 1;
}

void write(const C&c) {
    cout << c.x.x << ' ' << c.x.y << ' ' << c.y.x << ' ' << c.y.y;
}


int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N; cin >> N;

    map<C, int> P;
    map<C, int> R;
    vector<C> Q;
    for (int i = 0; i < N; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        C x{{a,b},{c,d}};
        x = norm(x);
        P[x] += 1;
        R[x] = rot(x);
        Q.push_back(x);

        //write(x); cout << endl;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        C &p = Q[i];
        for (int j = i+1; j < N; j++) {
            C &q = Q[j];
            for (int k = 0; k < 4; k++) {
                C u[4];
                ll cur = 1;
                for (int l = 0; l < 4; l++) {
                    u[l] = norm({{get(p,l+1),get(p,l)},{get(q,k-l),get(q,k-l-1)}});
                    int opts = P[u[l]];
                    //if (i == 2 && j == 5) { write(u[l]); cout << '=' << opts << endl; } 
                    if (u[l] == p) --opts;
                    if (u[l] == q) --opts;
                    for (int m = 0; m < l; m++) if (u[l] == u[m]) --opts;
                    if (opts <= 0) {
                        cur = 0;
                    } else {
                        cur *= opts*R[u[l]];
                    }
                }
                //if (cur != 0) {
                //    cout << i << ' ' << j << endl;
                //}
                ans += cur;
            }
        }
    }

    cout << ans/3 << endl;
}
