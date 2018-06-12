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

bool solve(ll A, ll B, ll C) {
	if (C >= B) {
		ll x = C + 1 - B;
		if (x >= A) x++;
		if (x * (B + 1) >= A * B) return false;
	}
	for (ll x = C / 2 - 5; x <= C / 2 + 7; x++) {
		if (x <= 0 || x == A) continue;
		ll id = x;
		if (x > A) id--;
		ll y = C + 1 - id;
		if (C >= B) y++;
		if (C >= B && y <= B) y--;
		if (y <= 0) continue;
		if (x * y >= A * B) return false;
	}
	return true;
}

ll solve() {
	ll A, B;
	scanf("%lld%lld", &A, &B);
	if (A > B) swap(A, B);
	ll L = A - 1, R = A + B;
	while(R - L > 1) {
		ll x = (L + R) / 2;
		if (solve(A, B, x))
			L = x;
		else
			R = x;
	}
	return L;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--)
		printf("%lld\n", solve());

	return 0;
}
