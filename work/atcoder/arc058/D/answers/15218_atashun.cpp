#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

ll mod_pow(ll x, ll k)
{
    ll res = 1;
    for (; k; x = x * x % MOD, k /= 2) if (k & 1) res = res * x % MOD;
    return res;
}

int H, W, A, B;
ll fact[200010];
ll ifact[200010];
ll ret;

ll comb(ll n, ll k)
{
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main() {
    cin >> H >> W >> A >> B;
    fact[0] = ifact[0] = 1;

    for (int i = 1; i < 200010; ++i) {
	fact[i] = fact[i-1] * i % MOD;
	ifact[i] = mod_pow(fact[i], MOD - 2);
    }

    for (int i = 1; i <= H - A; ++i) {
	ll t = comb(B - 1 + i - 1, B - 1);
	ll ad = t * comb(W - B - 1 + H - i, H - i);
	ret = (ret + ad) % MOD;
    }

    cout << ret << endl;
    
    return 0;
}