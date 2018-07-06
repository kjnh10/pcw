#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define Rrep(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int N, K;
int T[5][5] = {0};

int main() {
	scanf("%d %d", &N, &K);
	rep(i, N) rep(j, K) scanf("%d", &T[i][j]);
	rep(i, K) rep(j, K) rep(k, K) rep(l, K) rep(m, K) {
		if(!(T[0][i] ^ T[1][j] ^ T[2][k] ^ T[3][l] ^ T[4][m])) {
			printf("Found\n");
			return 0;
		}
	}
	printf("Nothing\n");
	return 0;
}