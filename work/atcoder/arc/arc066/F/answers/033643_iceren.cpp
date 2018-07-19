#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

typedef pair<long long, long long> Point;

const int N = 3e5 + 7;
const long long INF = 1LL << 60;
int n, val[N];
long long f[N], g[N], suffix[N], prefix[N];
long long ans[N][2];

long long det(const Point &a, const Point &b, const Point &c) {
	return (b.first - a.first) * (c.second - a.second) -
		(c.first - a.first) * (b.second - a.second);
}

class Solver {
private:
	vector<Point> convex;
	int ptr;
public:
	void clear() {
		ptr = 0;
		convex.clear();
	}
	Solver() {
		clear();
	}
	void insert(int pos, long long f, long long sum) {
		Point tmp = {pos, f + sum + 1LL * pos * (pos - 1) / 2};
		int m = convex.size();
		while (m >= 2 && det(convex[m - 2], convex.back(), tmp) >= 0) {
			convex.pop_back();
			m--;
		}
		convex.push_back(tmp);
		if (ptr >= convex.size() - 2) {
			ptr = convex.size() - 1;
		}
	}

	long long get_v(Point &a, int pos, long long sum) {
		return a.second - sum + 1LL * pos * (pos + 1) / 2 - a.first * pos;
	}
	long long calc(int pos, long long sum) {
		while (ptr > 0 && get_v(convex[ptr], pos, sum) <=
			get_v(convex[ptr - 1], pos, sum)) {
			ptr--;
		}
		//cout << convex[ptr].first << " --- " << convex[0].first << " " << get_v(convex[0], pos, sum) << " " << get_v(convex[ptr], pos, sum) << endl;
		return get_v(convex[ptr], pos, sum);
	}
	void show() {
		for (auto p : convex) {
			cout << "(" << p.first << ", " << p.second << ")" << endl;
		}
	}
};

Solver solver;
void solve(int l, int r) {
	if (l == r) return ;
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid + 1, r);
	static long long tmp[N];
	fill(tmp + l, tmp + r + 1, -INF);
	solver.clear();
	for (int i = l - 1; i < mid; i++) {
		solver.insert(i, f[i], prefix[i]);
	}
	for (int i = mid + 1; i <= r; i++) {
		tmp[i] = solver.calc(i, prefix[i]) + g[i + 1];
	}
	for (int i = r; i > mid; i--) {
		if (i < r) tmp[i] = max(tmp[i], tmp[i + 1]);
		ans[i][1] = max(ans[i][1], tmp[i]);
	}
	solver.clear();
	fill(tmp + l, tmp + r + 1, -INF);
	for (int i = r + 1; i > mid + 1; i--) {
		solver.insert(n + 1 - i, g[i], suffix[i]);
	}
	for (int i = mid; i >= l; i--) {
		tmp[i] = solver.calc(n + 1 - i, suffix[i]) + f[i - 1];
		//cout << "tmp = " << tmp[i] << endl;
	}
	//solver.show();
	for (int i = l; i <= mid; i++) {
		if (i > l) tmp[i] = max(tmp[i], tmp[i - 1]);
		ans[i][1] = max(ans[i][1], tmp[i]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
		prefix[i] = prefix[i - 1] + val[i];
		ans[i][1] = -INF;
	}
	for (int i = n; i >= 1; i--) {
		suffix[i] = suffix[i + 1] + val[i];
	}
	{
		Solver pre;
		pre.insert(0, 0, 0);
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = max(f[i - 1], pre.calc(i, prefix[i]));
			pre.insert(i, f[i], prefix[i]);
		}
		Solver suf;
		suf.insert(0, 0, 0);
		g[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			ans[i][0] = f[i - 1] + g[i + 1];
			g[i] = max(g[i + 1], suf.calc(n + 1 - i, suffix[i]));
			suf.insert(n + 1 - i, g[i], suffix[i]);
		}
	}
	solve(1, n);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int p, x;
		scanf("%d %d", &p, &x);
		printf("%lld\n", max(ans[p][0], ans[p][1] + val[p] - x));
	}
	return 0;
}
