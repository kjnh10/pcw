#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	vector<int> c(m), d(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		pair<int, int> mn(1e9, 1e9);
		for (int j = 0; j < m; j++) {
			int e = abs(c[j] - a[i]) + abs(d[j] - b[i]);
			mn = min(mn, make_pair(e, j));
		}
		cout << mn.second + 1 << endl;
	}
}
