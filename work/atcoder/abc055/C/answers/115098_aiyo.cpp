#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	if (n * 2 >= m) {
		ans = m / 2;
	} else {
		ll res = m - 2 * n;
		ans = n + res / 4;
	}
	
	cout << ans << endl;
	
	return 0;
}