#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007LL
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  xtimex  Problem:  / Link:  ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

ll N, K;

ll ans = 0LL;

ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p & 1) a = a * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return a;
}
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    ll x = N - 1 + K;
    ll y = K;
    ll fact[220000];

    fact[0] = 1;

    FOR(i, 1, 220000) {
        fact[i] = (i*fact[i - 1]) % MOD;
    }

    ans = ((fact[x] * mod_inverse(fact[y], MOD))%MOD)*mod_inverse(fact[x - y], MOD) % MOD;

    cout << ans << endl;

    return 0;
}