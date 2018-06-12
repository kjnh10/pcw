#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class DSU {
	std::vector<int> dat;

public:
	DSU(int n) : dat(n, -1) {}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)	return false;
		if (dat[x] > dat[y]) {
			std::swap(x, y);
		}
		dat[x] += dat[y];
		dat[y] = x;
		return true;
	}

	int find(int x) {
		if (dat[x] < 0) {
			return x;
		}
		return dat[x] = find(dat[x]);
	}
};

int main() {
	int n;
	std::cin >> n;

	std::vector<int> xs(n), ys(n);
	std::vector<int> px(n);
	std::vector<int> py(n);
	for (int i = 0; i < n; i++) {
		std::cin >> xs[i] >> ys[i];
		px[i] = i;
		py[i] = i;
	}

	std::sort(px.begin(), px.end(), [&](int i, int j) { return xs[i] < xs[j]; });
	std::sort(py.begin(), py.end(), [&](int i, int j) { return ys[i] < ys[j]; });
	
	std::vector<int> us, vs, ws;
	for (int i = 0; i < n - 1; i++) {
		int u = px[i];
		int v = px[i + 1];
		us.push_back(u);
		vs.push_back(v);
		ws.push_back(xs[v] - xs[u]);
	}
	for (int i = 0; i < n - 1; i++) {
		int u = py[i];
		int v = py[i + 1];
		us.push_back(u);
		vs.push_back(v);
		ws.push_back(ys[v] - ys[u]);
	}

	std::vector<int> ps(us.size());
	for (int i = 0; i < ps.size(); i++) {
		ps[i] = i;
	}
	std::sort(ps.begin(), ps.end(), [&](int i, int j) { return ws[i] < ws[j]; });

	long long ans = 0;

	DSU dsu(n);

	for (int i : ps) {
		int u = us[i];
		int v = vs[i];
		int w = ws[i];
		if (dsu.unite(u, v)) {
			ans += w;
		}
	}
	std::cout << ans << std::endl;
}
