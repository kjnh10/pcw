#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5L + 11;
ll a[N], b[N];
bool ans[N];

int main() {
	int n;
	cin >> n >> b[0];
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", a + i);
		b[i] = min(b[i - 1], abs(b[i - 1] - a[i]));
		//cout << i << ' ' << b[i] << '\n';
	}
	ll suf = 0;
	for(int i = n; i >= 1; i --) {
		//cout << i << ' ' << suf << '\n';
		if(suf < b[i - 1])
			ans[i] = 1;
		if(suf >= a[i] / 2)
			suf += a[i];
	}
	int q; cin >> q;
	while(q --) {
		ll x; scanf("%lld", &x);
		printf("%s\n", (ans[x] ? "YES" : "NO"));
	}
	return 0;
}