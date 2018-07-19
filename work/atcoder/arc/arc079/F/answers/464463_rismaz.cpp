
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

int mex(VI &vec) {
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    
    vec.pb(INF);
    FORE(i,vec) if (vec[i] != i) {
        return i;
    }
    
    assert(false);
}

int getValue(int v, VVI &g, VI &value) {
    if (value[v] == -1) {
        VI vec;
        for (int u : g[v]) {
            vec.pb(getValue(u, g, value));
        }
        
        value[v] = mex(vec);
    }
    
    return value[v];
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    VI in(n);
    VVI g(n);
    
    FOR(i,0,n-1) {
        int p;
        cin >> p; p--;
        
        in[i] = p;
        g[p].pb(i);
    }
    
    int v = 0;
    FOR(_,1,n) v = in[v];
    
    VB onCycle(n, false);
    
    while (!onCycle[v]) {
        onCycle[v] = true;
        v = in[v];
    }
    
    VI value(n,-1);
    
    FOR(i,0,n-1) if (!onCycle[i]) {
        getValue(i, g, value);
    }
    
    VI valuesForV;
    
    VI see;
    for (int u : g[v]) if (!onCycle[u]) {
        see.pb(value[u]);
    }
    
    VI vec = see;
    
    int mx = mex(vec);
    valuesForV.pb(mx);
    
    vec.pb(mx);
    valuesForV.pb(mex(vec));
    
    int x;
    for (int u : g[v]) if (onCycle[u]) {
        x = u;
        break;
    }
    
    for (int valueChosen : valuesForV) {
        VI valueHere = value;
        valueHere[v] = valueChosen;
        
        VI vecHere = see;
        vecHere.pb(getValue(x, g, valueHere));
        
        if (valueChosen == mex(vecHere)) {
            cout << "POSSIBLE";
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}

/*************************************************************************/
