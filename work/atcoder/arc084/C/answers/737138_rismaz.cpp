
#include <bits/stdc++.h>

#define FOR(i,b,e) for(ll i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(ll i=(b); i >= (e); --i)
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

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    VI a(n), b(n), c(n);
    
    FOR(i,0,n-1) cin >> a[i];
    FOR(i,0,n-1) cin >> b[i];
    FOR(i,0,n-1) cin >> c[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    
    FOR(i,0,n-1) {
        ll inA = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll inB = c.end() - upper_bound(c.begin(), c.end(), b[i]);
    
        ans += inA * inB;
    }
    
    cout << ans;

    return 0;
}

/*************************************************************************/
