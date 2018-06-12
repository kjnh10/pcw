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

char in[200050];
int R[26][200050];
int L[26][200050];
int pos[200050];
int main() {
	scanf("%s", in + 1);
	int N = strlen(in + 1), i, j;
	for (i = 0; i < 26; i++) {
		for (j = 1; j <= N; j++) {
			L[i][j] = L[i][j - 1];
			if (in[j] == 'a' + i) L[i][j] = j;
		}
		R[i][N + 1] = N + 1;
		for (j = N; j >= 1; j--) {
			R[i][j] = R[i][j + 1];
			if (in[j] == 'a' + i) R[i][j] = j;
		}
	}

	int p = N+1, len = 0;
	pos[0] = N + 1;
	while (1) {
		len++;
		int mn = N + 1;
		for (i = 0; i < 26; i++) mn = min(mn, L[i][p - 1]);
		pos[len] = mn;
		if (mn == 0) break;
		p = mn;
	}
	
	for (i = 1, j = 1; i <= len; i++) {
		for (int k = 0; k < 26; k++) {
			int p = R[k][j];
			if (pos[len - i] <= p) {
				j = p + 1;
				printf("%c", 'a' + k);
				break;
			}
		}
	}
	return !printf("\n");
}