#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 100005;

int n, m;

struct data {
	int x, y, w;

	data(int a = 0, int b = 0, int c = 0) : x(a), y(b), w(c) {} ;

	bool operator < (const data &d) const {
		return w < d.w;
	}
} a[mxn], b[mxn], c[mxn << 1];

int fa[mxn];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

signed main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].w), a[i].x = i;
		scanf("%d", &b[i].w), b[i].x = i;
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	for (int i = 1; i < n; ++i) {
		c[m++] = data(a[i].x, a[i + 1].x, a[i + 1].w - a[i].w);
		c[m++] = data(b[i].x, b[i + 1].x, b[i + 1].w - b[i].w);
	}

	sort(c, c + m);

	long long ans = 0;

	for (int i = 1; i <= n; ++i)fa[i] = i;

	for (int i = 0; i < m; ++i) {
		int x = find(c[i].x);
		int y = find(c[i].y);

		if (x != y) {
			ans += c[i].w, fa[x] = y;
		}
	}

	printf("%lld\n", ans);
}