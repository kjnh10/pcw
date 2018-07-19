#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, L, Q;
int X[101010];
int bk[17][101010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", X + i);
	scanf("%d%d", &L, &Q);

	int pre = 0;
	for (int i = 0; i < N; ++i) {
		while (X[i] - X[pre] > L) ++pre;
		bk[0][i] = pre;
	}

	for (int i = 1; i < 17; ++i) {
		for (int j = 0; j <= N; ++j) {
			bk[i][j] = bk[i - 1][bk[i - 1][j]];
		}
	}

	for (; Q--;) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		if (a == b) {
			puts("0");
			continue;
		}
		if (a > b) swap(a, b);

		int ret = 0;
		for (int i = 16; i >= 0; --i) {
			if (bk[i][b] > a) {
				ret += 1 << i;
				b = bk[i][b];
			}
		}

		printf("%d\n", ret + 1);
	}
	return 0;
}
