#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll MOD = (ll)1e9 + 7LL;

map<ll,ll> memo;

ll f(ll n){

	if (memo.count(n)) return memo[n];

	if (n <= 2LL) return n;

	ll res = (f(n/2LL) + f((n-1LL)/2LL)) % MOD;
	res = (res + f((n+1LL)/2LL)) % MOD; 

	return memo[n] = res;
}

int main()
{
	memo.clear();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll N; cin >> N;

	ll res = f(N+1LL);
	cout << res << endl;

	return 0;
}