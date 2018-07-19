#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N, K; cin >> N >> K;
	vector<int> dp(N + 1);
	dp[N] = 1;
	rep(k, K - 1) {
		vector<int> _dp(N + 1), imos(N + 1);
		for (int i = 0; i <= N; i++) {
			if (i + k < N) _dp[i] = (_dp[i] + dp[i]) % MOD;
			if (i) imos[i - 1] = (imos[i - 1] + dp[i]) % MOD;
		}
		for (int i = N - 1; i >= 0; i--)
			imos[i] = (imos[i] + imos[i + 1]) % MOD;
		for (int i = 0; i <= N; i++)
			_dp[i] = (_dp[i] + imos[i]) % MOD;
		dp = _dp;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = (ans + dp[i]) % MOD;
	rep(t, N - K - 1) ans = ans * 2 % MOD;
	cout << ans << endl;
}
