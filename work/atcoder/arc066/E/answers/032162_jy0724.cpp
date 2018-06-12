#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
using namespace std;
const int maxn = 100010;
int n; ll b[maxn], c[maxn];
struct epoch { int op; ll ave; } a[maxn];
int main() {
	scanf("%d", &n); char ch[10]; 
	scanf("%lld", &a[1].ave);
	rep(i, 2, n) {
		scanf("%s%lld", ch, &a[i].ave);
		if (ch[0] == '-') a[i].op = 1;
	}
	rep(i, 1, n) b[i] = b[i - 1] + a[i].ave; int las = 0;
	rep(i, 1, n) c[i] = c[i - 1] + ((a[i].op) ? - a[i].ave : a[i].ave);
	ll ans = c[n];
	rep(i, 1, n) if (a[i].op) {
		if (!las) {
			las = i;
			continue;
		}
		ans = max(ans, c[las] - (c[i - 1] - c[las]) + b[n] - b[i - 1]);
		las = i;
	}
	printf("%lld", ans);
	return 0;
}