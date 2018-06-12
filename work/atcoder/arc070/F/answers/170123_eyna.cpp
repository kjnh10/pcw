// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e5 + 5, mod = (int) 0;
int n, done;
map<int, int> mp[N];
int ask(int x, int y) {
	if (mp[x][y]) return mp[x][y] - 1;
	++done;
	if (done >= 2 * n) {
		assert(0);
	}
	cout << "? " << x << ' ' << y << endl;
	fflush(stdout);
	char res;
	cin >> res;
	mp[x][y] = (res == 'Y') + 1;
	return res == 'Y';
}
char s[N];
int main() {
	int a, b;
	cin >> a >> b;
	if (a <= b) {
		cout << "Impossible" << endl;
		fflush(stdout);
		return 0;
	}
	vector<int> all;
	n = a + b;
	for (int j = 0; j < n; ++j) {
		if (!all.size()) {
			all.push_back(j);
		} else {
			int x = ask(all.back(), j);
			if (!x) {
				all.pop_back();
			} else {
				all.push_back(j);
			}
		}
	}
	int good = all.back();
	/*
	while (all.size() > 1) {
		vector<int> nx;
		if (all.size() == 3) {
			int x = ask(all[0], all[2]);
			int y = ask(all[1], all[2]);
			if (x + y >= 1) {
				nx.push_back(all[2]);
			} else {
				nx.push_back(all[0]);
			}
		} else {
			if ((all.size() & 1) && ((all.size() / 2) & 1)) {
				nx.push_back(all.back()); all.pop_back();
				nx.push_back(all.back()); all.pop_back();
			}
			for (int j = 0; j < (int) all.size(); j += 2) {
				int x = ask(all[j], all[j + 1]);
				if (x) nx.push_back(all[j + 1]);
			}
			if (all.size() & 1)
				nx.push_back(all.back());
		}
		all = nx;
	}
	int good = all[0];
	*/
	s[good] = '1';
	for (int j = 0; j < n; ++j)
		if (good != j) {
			s[j] = (ask(good, j) ? '1' : '0');
		}
	cout << "! ";
	string res;
	for (int j = 0; j < n; ++j) res += s[j];
	cout << res << endl;
	return 0;

}

