#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
int n, K, L;
int c[MAXN], d[MAXN];
int f(int x) {
	if (x == c[x]) return x;
	return c[x] = f(c[x]);
}
int g(int x) {
	if (x == d[x]) return x;
	return d[x] = g(d[x]);
}
int ans[MAXN];
unordered_map <int, int> v[MAXN];
int main() {
	scanf("%d%d%d", &n, &K, &L);
	for (int i = 1; i <= n; i++) c[i] = d[i] = i;
	for (int i = 0; i < K; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x = f(x); y = f(y);
		c[x] = y;
	}
	for (int i = 0; i < L; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x = g(x); y = g(y);
		d[x] = y;
	}
	for (int i = 1; i <= n; i++) {
		c[i] = f(i);
		d[i] = g(i);
		v[c[i]][d[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = v[f(i)][g(i)];
		printf("%d ", ans[i]);
	}
	puts("");
}