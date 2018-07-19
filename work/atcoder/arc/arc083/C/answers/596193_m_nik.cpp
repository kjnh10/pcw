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

const int C = 3010;
bool dp1[C], dp2[C];
int a, b, c, d, e, f;
int P, Q;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> a >> b >> c >> d >> e >> f;
	dp1[0] = 1;
	dp2[0] = 1;
	for (int x = 0; x < C; x++) {
		if (dp1[x]) {
			if (x + a < C)
				dp1[x + a] = 1;
			if (x + b < C)
				dp1[x + b] = 1;
		}
		if (dp2[x]) {
			if (x + c < C)
				dp2[x + c] = 1;
			if (x + d < C)
				dp2[x + d] = 1;
		}
	}

	P = 0;
	Q = a;
	for (int x = 1; x <= f / 100; x++) {
		if (!dp1[x]) continue;
		for (int y = 0; 100 * x + y <= f; y++) {
			if (y > x * e) break;
			if (!dp2[y]) continue;
			if (y * Q > x * P) {
				P = y;
				Q = x;
			}
		}
	}
	cout << P + 100 * Q << " " << P << endl;


	return 0;
}
