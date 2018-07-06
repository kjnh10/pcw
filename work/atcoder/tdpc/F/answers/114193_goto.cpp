#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf (int)1000000007
#define mod (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

int dpr[1919364];

signed main() {
	int dn, dk;
	cin >> dn >> dk;
	dpr[0] = 1;
	dpr[1] = 1;
	tfor(i, 2, dn - 1) {
		if(i - dk - 1 < 0) {
			dpr[i] = dpr[i - 1] * 2 % mod;
		}
		else {
			dpr[i] = (dpr[i - 1] * 2 - dpr[i - dk - 1] + mod) % mod;
		}
	}
	cout << (dpr[dn - 1] - dpr[dn - dk] + mod) % mod << endl;
}
