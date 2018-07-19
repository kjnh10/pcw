#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 12;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

vector <pll> conn[100050];
ll dis[100050];
int main() {
	int N, i, j, Q, K;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		conn[t1].emplace_back(t3, t2);
		conn[t2].emplace_back(t3, t1);
	}
	scanf("%d %d", &Q, &K);

	memset(dis, 0x3f, sizeof(dis));
	vector <int> Vu;
	dis[K] = 0;
	Vu.push_back(K);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (dis[it.second] == LL_INF) {
				dis[it.second] = dis[Vu[i]] + it.first;
				Vu.push_back(it.second);
			}
		}
	}
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%lld\n", dis[t1] + dis[t2]);
	}
	return 0;
}