#include <bits/stdc++.h>
#include <random>
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
typedef pair<ll_i, int> P;
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
struct edge { int v, a, b; };

int main() {
	int N, K; cin >> N >> K;
	vector<int> b(N);
	rep(i, N) {
		int x; scanf("%d", &x);
		b[x - 1]++;
	}
	sort(b.begin(), b.end());
	int ans = 0;
	rep(x, N - K) ans += b[x];
	cout << ans << endl;
}
