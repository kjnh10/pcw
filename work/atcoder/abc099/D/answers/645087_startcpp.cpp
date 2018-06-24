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
#include <cstring>
#include <cmath>
#include <cassert>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int n, c;
int d[30][30];
int a[500][500];
int cnt[3][30];
int iwakan[3][30];

signed main() {
	int i, j, k;
	
	cin >> n >> c;
	rep(i, c) rep(j, c) cin >> d[i][j];
	rep(i, n) rep(j, n) { cin >> a[i][j]; a[i][j]--; }
	
	rep(i, n) {
		rep(j, n) {
			int type = (i + j) % 3;
			cnt[type][a[i][j]]++;
		}
	}
	
	rep(i, 3) {
		rep(j, c) {	//色jで合わせる
			rep(k, c) {
				iwakan[i][j] += cnt[i][k] * d[k][j];
			}
		}
	}
	
	int ans = 1e+15;
	rep(i, c) {
		rep(j, c) {
			rep(k, c) {
				if (i == j) continue;
				if (j == k) continue;
				if (k == i) continue;
				int ssum = iwakan[0][i] + iwakan[1][j] + iwakan[2][k];
				ans = min(ans, ssum);
			}
		}
	}
	cout << ans << endl;
	return 0;
}