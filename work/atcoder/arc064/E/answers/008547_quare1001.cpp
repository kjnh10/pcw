#include <queue>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n; double x[1009], y[1009], r[1009]; vector<pair<int, double> > G[1009];
int main() {
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i + 2] >> y[i + 2] >> r[i + 2];
	for (int i = 0; i < n + 2; i++) {
		for (int j = i + 1; j < n + 2; j++) {
			double dist = max(hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j], 0.0);
			G[i].push_back(make_pair(j, dist));
			G[j].push_back(make_pair(i, dist));
		}
	}
	priority_queue<pair<double, int> > que; que.push(make_pair(0, 0));
	vector<double> d(n + 2, 1.0e+10); d[0] = 0;
	while (!que.empty()) {
		int u = que.top().second; que.pop();
		for (pair<int, double> e : G[u]) {
			if (d[e.first] > d[u] + e.second) {
				d[e.first] = d[u] + e.second;
				que.push(make_pair(-d[e.first], e.first));
			}
		}
	}
	cout << fixed << setprecision(15) << d[1] << endl;
	return 0;
}