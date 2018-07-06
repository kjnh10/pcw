#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int main() {
	int n;
	scanf("%d", &n);
	int tmp = 2025 - n;
	FOR(i, 1, 10) FOR(j, 1, 10) {
		if(i * j == tmp) printf("%d x %d\n", i, j);
	}
	return 0;
}