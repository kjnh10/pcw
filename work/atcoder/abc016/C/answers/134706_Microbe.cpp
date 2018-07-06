#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define Rrep(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int N, M, A, B;
int judge[11][11];
int cnt[11] = {0};

int main() {
	scanf("%d %d", &N, &M);
	memset(judge, 0, sizeof(judge));
	rep(i, M) {
		scanf("%d %d", &A, &B);
		judge[B][A] = 2;
		judge[B][B] = 2;
		judge[A][B] = 2;
		judge[A][A] = 2;
	}
	FOR(i, 1, N + 1) {
		FOR(j, 1, N + 1) {
			if(judge[i][j] == 2) {
				FOR(k, 1, N + 1) {
					if(judge[j][k] == 2 && judge[i][k] == 0) {
						judge[i][k] = 1;
					}
				}
			}
		}
	}
	FOR(i, 1, N + 1) FOR(j, 1, N + 1) if(judge[i][j] == 1) ++cnt[i];
	FOR(i, 1, N + 1) printf("%d\n", cnt[i]);
	return 0;
}