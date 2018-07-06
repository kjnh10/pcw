#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

bool ok[19191];

signed main() {
	trep(i, 10000) {
		ok[i] = false;
	}
	ok[0] = true;
	int dn;
	cin >> dn;
	rep(i, dn) {
		int w;
		cin >> w;
		rrep(j, 10000 - w + 1) {
			ok[j + w] = ok[j + w] || ok[j];
		}
	}
	int ans = 0;
	trep(i, 10000) {
		if(ok[i]) {
			ans++;
		}
	}
	cout << ans << endl;
}
