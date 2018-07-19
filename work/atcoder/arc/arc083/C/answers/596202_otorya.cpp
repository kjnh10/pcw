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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

bool dp1[3050];
bool dp2[3050];
int main() {
	int A, B, C, D, E, F, i, j;
	scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

	dp1[0] = true;
	dp2[0] = true;
	for (i = A; i <= F; i++) dp1[i] |= dp1[i - A];
	for (i = B; i <= F; i++) dp1[i] |= dp1[i - B];
	for (i = C; i <= F; i++) dp2[i] |= dp2[i - C];
	for (i = D; i <= F; i++) dp2[i] |= dp2[i - D];
	
	ll a1 = 1, a2 = 0;
	for (i = 1; i * 100 <= F; i++) {
		for (j = 0; i * 100 + j <= F; j++) {
			if (j > i*E) continue;
			if (!dp1[i] || !dp2[j]) continue;
			ll v1 = i * 100 + j, v2 = j;
			if (a2*v1 <= a1*v2) {
				a1 = v1;
				a2 = v2;
			}
		}
	}
	return !printf("%lld %lld\n", a1, a2);
}