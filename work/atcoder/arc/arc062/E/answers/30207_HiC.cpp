#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

vector<int> c[500];
int n;
ll cnk[500][5];
map<vector<int>, int > mm;
ll fc[5];

void init() {
	fc[0] = 1;
	fc[1] = 1;
	fc[2] = 2;
	fc[3] = 6;
	fc[4] = 24;
	for (int n = 0; n < 500; ++n)
		for (int k = 0; k < 5; ++k) {
			if (n == k || k == 0)
				cnk[n][k] = 1;
			else if (n < k)
				cnk[n][k] = 0;
			else
				cnk[n][k] = cnk[n - 1][k] + cnk[n - 1][k - 1];
		}
}

int mlt(vector<int> vv) {
	vector<int> vv2 = vv;
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		rotate(vv2.begin(), vv2.begin() + 1, vv2.end());
		if (vv2 == vv)
			++cnt;
	}
	return cnt;
}

vector<int> srt(vector<int> vv) {
	vector<int> vv2 = vv;
	for (int i = 0; i < 4; ++i) {
		rotate(vv2.begin(), vv2.begin() + 1, vv2.end());
		if (vv2 < vv)
			vv = vv2;
	}
	return vv;
}

void del(int x) {
	--mm[c[x]];
}

void add(int x) {
	++mm[c[x]];
}



int main() {
	init();
	cin >> n;
	for (int j = 0; j < n; ++j)
		c[j].resize(4);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j)
			cin >> c[i][j];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		c[i] = srt(c[i]);
	for (int i = 0; i < n; ++i)
		add(i);
	for (int i = 0; i < n; ++i) {
		del(i);
		for (int j = i + 1; j < n; ++j) {
			del(j);
			for (int it = 0; it < 4; ++it) {
				rotate(c[i].begin(), c[i].begin() + 1, c[i].end());
				vector<vector<int> > vv;
				vv.push_back({c[i][0], c[j][1], c[j][0], c[i][1]});
				vv.push_back({c[i][3], c[j][2], c[j][1], c[i][0]});
				vv.push_back({c[i][2], c[j][3], c[j][2], c[i][3]});
				vv.push_back({c[i][1], c[j][0], c[j][3], c[i][2]});
				for (int k = 0; k < 4; ++k)
					vv[k] = srt(vv[k]);
				vector<int> was(4, 0);
				ll ml = 1;
				for (int k = 0; k < 4; ++k) {
					if (!was[k]) {
						int cnt = 0;
						for (int k1 = 0; k1 < 4; ++k1)
							if (vv[k] == vv[k1])
								++cnt, was[k1] = 1;
						ml *= cnk[mm[vv[k]]][cnt] * fc[cnt];
					}
					ml *= mlt(vv[k]);
				}
				ans += ml;
			}
			add(j);
		}
	}
	cout << ans << "\n";
	return 0;
}


