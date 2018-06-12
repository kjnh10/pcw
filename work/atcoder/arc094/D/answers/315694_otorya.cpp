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

int IT_MAX = 1 << 20;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

ll mymul(ll a, ll b) {
	if (LL_INF / b < a) return LL_INF;
	else return min(LL_INF, a*b);
}

vector <pll> Vu1;
vector <pll> Vu2;
int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		ll A, B, i, j;
		scanf("%lld %lld", &A, &B);

		ll st = 1, en = 1e12, mi, rv = 0;
		while (st <= en) {
			mi = (st + en) / 2;
			if (mi == 2) {
				mi = mi;
			}
			Vu1.clear();
			Vu2.clear();
			if (mi < A) Vu1.emplace_back(1, mi);
			else {
				if(A-1 != 0) Vu1.emplace_back(1, A - 1);
				if(mi-A+1 != 0) Vu1.emplace_back(A + 1, mi - A + 1);
			}
			if (mi < B) Vu2.emplace_back(mi, mi);
			else {
				if(mi-B+1 != 0) Vu2.emplace_back(mi + 1, mi - B + 1);
				if(B-1 != 0) Vu2.emplace_back(B - 1, B - 1);
			}

			bool ans = true;
			int p1 = 0, p2 = 0;
			while (p1 != Vu1.size()) {
				ll c = min(Vu1[p1].second, Vu2[p2].second);
				
				ll s1 = Vu1[p1].first, e1 = Vu2[p2].first;

				ll v1, v2;
				if (e1 % 2 == s1 % 2) {
					v1 = v2 = (e1 - s1) / 2;
				}
				else {
					v1 = (e1 - s1 - 1) / 2;
					v2 = (e1 - s1 + 1) / 2;
				}

				ll mx = -LL_INF;
				if (0 <= v1 && v1 < c) mx = max(mx, mymul(s1 + v1, e1 - v1));
				if (0 <= v2 && v2 < c) mx = max(mx, mymul(s1 + v2, e1 - v2));
				mx = max(mx, mymul(s1, e1));
				mx = max(mx, mymul(s1 + c - 1, e1 - c + 1));
				if (mx >= A*B) {
					ans = false;
					break;
				}
				Vu1[p1].first += c;
				Vu2[p2].first -= c;
				Vu1[p1].second -= c;
				Vu2[p2].second -= c;
				if (Vu1[p1].second == 0) p1++;
				if (Vu2[p2].second == 0) p2++;
			}
			if (ans) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		printf("%lld\n", rv);
	}
	return 0;
}