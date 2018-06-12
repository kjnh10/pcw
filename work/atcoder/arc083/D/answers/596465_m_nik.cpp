#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 303;
int n;
ll a[N][N];
ll ans = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%lld", &a[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			ll w = a[i][j] + 1;
			for (int k = 0; k < n; k++) {
				if (i == k || j == k) continue;
				w = min(w, a[i][k] + a[k][j]);
			}
			if (w < a[i][j]) {
				printf("-1\n");
				return 0;
			}
			if (w > a[i][j]) ans += a[i][j];
		}
	printf("%lld\n", ans);

	return 0;
}
