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
#include <random>
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

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	vector<ll> sum(N + 1);
	for (int i = 0; i < N; i++)
		sum[i + 1] = sum[i] + a[i];
	ll ans = 0;
	for (int i = 0; i + K <= N; i++)
		ans += sum[i + K] - sum[i];
	cout << ans << endl;
}
