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
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  xtimex  Problem: ABC024 D / Link: http://abc024.contest.atcoder.jp/tasks/abc024_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */


ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p & 1) a = a * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return a;
}

//逆元　1/a (mod m) => a^(m-2) (mod m)
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll a, b, c;

    cin >> a >> b >> c;
    ll d = (b*c%MOD - a*b%MOD - a*c%MOD + MOD + MOD) % MOD;
    ll r = ((a*c%MOD - b*c%MOD+MOD) % MOD)*mod_inverse(d, MOD)%MOD;
    ll x = ((a*b%MOD - b*c%MOD+MOD) % MOD)*mod_inverse(d, MOD)%MOD;


    cout << r << " " << x << endl;

    return 0;
}