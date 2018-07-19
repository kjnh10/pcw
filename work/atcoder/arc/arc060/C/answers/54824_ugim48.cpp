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
using namespace std;

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
double EPS = 1e-10;

ll dp[51][2501];

int main() {
	int N, A; cin >> N >> A;
	vector<int> a(N);
	for (int& x: a) cin >> x;
	dp[0][0] = 1;
	for (int x: a) {
		for (int k = 50; k >= 0; k--)
			for (int y = 0; y <= 2500; y++) {
				if (!dp[k][y]) continue;
				dp[k + 1][y + x] += dp[k][y];
			}
	}
	ll ans = 0;
	for (int k = 1; k <= 50; k++)
		for (int y = 0; y <= 2500; y++)
			if (k * A == y)
				ans += dp[k][y];
	cout << ans << endl;
}
