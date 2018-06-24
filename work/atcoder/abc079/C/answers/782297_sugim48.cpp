#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;
struct edge { int i, v, w; };

int main() {
	string s; cin >> s;
	vector<int> a(4);
	rep(i, 4) a[i] = s[i] - '0';
	rep(S, 1<<3) {
		int ans = a[0];
		rep(i, 3) if (S>>i & 1) ans += a[i + 1]; else ans -= a[i + 1];
		if (ans == 7) {
			string s = "0-0-0-0=7";
			rep(i, 4) s[i * 2] = '0' + a[i];
			rep(i, 3) if (S>>i & 1) s[i * 2 + 1] = '+';
			cout << s << endl;
			return 0;
		}
	}
}
