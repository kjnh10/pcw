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

const int N = 200200;
ll L;
ll G = 0;
int m;
int go[N][2];
char s[N];
int q, n;

ll getG(ll x) {
	if (x <= 0) return 0;
	ll res = 1;
	while(x % 2 == 0) {
		x >>= 1;
		res <<= 1;
	}
	return res;
}

void dfs(int v, ll h) {
	if (v == -1) {
		if (L >= h) G ^= getG(L + 1 - h);
		return;
	}
	if (go[v][0] == -1 && go[v][1] == -1) return;
	dfs(go[v][0], h + 1);
	dfs(go[v][1], h + 1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		go[i][0] = go[i][1] = -1;
	m = 1;

	scanf("%d%lld", &q, &L);
	while(q--) {
		scanf("%s", s);
		n = strlen(s);
		int v = 0;
		for (int i = 0; i < n; i++) {
			int y = (int)(s[i] - '0');
			if (go[v][y] == -1) {
				go[v][y] = m++;
			}
			v = go[v][y];
		}
	}
	dfs(0, 0);
	if (G == 0)
		printf("Bob\n");
	else
		printf("Alice\n");

	return 0;
}
