#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n, m;
int x[1000], y[1000], z[1000];
int a[1000];

signed main() {
	int i, j;
	
	cin >> n >> m;
	rep(i, n) cin >> x[i] >> y[i] >> z[i];
	
	int ans = 0;
	rep(i, 8) {
		rep(j, n) {
			a[j] = 0;
			if (i % 2 == 1) a[j] -= x[j]; else a[j] += x[j];
			if ((i / 2) % 2 == 1) a[j] -= y[j]; else a[j] += y[j];
			if ((i / 4) % 2 == 1) a[j] -= z[j]; else a[j] += z[j];
		}
		sort(a, a + n, greater<int>());
		
		int score = 0;
		rep(j, m) {
			score += a[j];
		}
		ans = max(ans, score);
	}
	cout << ans << endl;
	return 0;
}