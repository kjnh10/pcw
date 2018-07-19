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

char in[2][55];
vector <int> Vin;

int u[55];
ll dp[55];
int main() {
	int N, i, j;
	scanf("%d %s %s", &N, in[0], in[1]);

	for (i = 0; i < N;) {
		if (i + 1 == N || in[0][i] == in[1][i]) {
			Vin.push_back(1);
			i++;
		}
		else {
			Vin.push_back(2);
			i += 2;
		}
	}

	dp[0] = 6;
	if (Vin[0] == 1) dp[0] = 3;
	for (i = 1; i < Vin.size(); i++) {
		if (Vin[i] == 1 && Vin[i-1] == 1) dp[i] = dp[i - 1] * 2 % MOD;
		if (Vin[i] == 1 && Vin[i - 1] == 2) dp[i] = dp[i - 1];
		if (Vin[i] == 2 && Vin[i - 1] == 1) dp[i] = dp[i - 1] * 2 % MOD;
		if (Vin[i] == 2 && Vin[i - 1] == 2) dp[i] = dp[i - 1] * 3 % MOD;
	}
	return !printf("%lld\n", dp[Vin.size() - 1]);
}