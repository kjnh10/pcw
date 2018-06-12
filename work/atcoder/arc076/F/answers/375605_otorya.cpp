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
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> Vv[200050];

priority_queue <int, vector<int>, greater<int>> Hx;
vector <int> Vu;
ll getv(int a, int M) {
	int i;
	while (!Hx.empty()) Hx.pop();
	Vu.clear();
	for (i = 1; i <= M; i++) {
		for (auto it : Vv[i]) Hx.push(it);
		if (i >= M - a + 1) {
			if (Hx.empty()) return -LL_INF;
			Hx.pop();
		}
	}
	for (auto it : Vv[M + 1]) Hx.push(it);
	while (!Hx.empty()) {
		Vu.push_back(Hx.top());
		Hx.pop();
	}

	int st = 1, en = min((int)Vu.size(), M - a), mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;

		for (i = 0; i < mi; i++) if (Vu[Vu.size() - mi + i] < i + 1) break;
		if (i >= mi) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return a + rv;
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	//N = 200000, M = 199999;
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		//t1 = 1, t2 = 2;
		Vv[t2].push_back(t1);
	}
	
	int st = 0, en = min(N, M), mi;
	while (st < en) {
		int mi1 = (st + en) / 2;
		int mi2 = mi1 + 1;
		
		ll v1 = getv(mi1, M);
		ll v2 = getv(mi2, M);
		if (v1 >= v2) en = mi2 - 1;
		else st = mi1 + 1;
	}
	ll v = getv(st, M);
	return !printf("%lld\n", N - v);
}