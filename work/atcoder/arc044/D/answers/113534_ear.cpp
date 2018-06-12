#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*) array, (T*) (array + N), val);
}
pii Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};

ll mod_pow(ll x, ll n, int mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x%mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}

signed main() {
	int n;
	scanf("%d", &n);
	map<int,int> num;
	int Max = 0;
	REP(i, n) {
		int a;
		scnaf("%d", &a);
		num[a]++;
		Max = max(Max, a);
		if (!i && a != 0) {
			printf("0\n");
			return 0;
		}
	}
	if (num[0] != 1) {
		printf("0\n");
		return 0;
	}

	ll ans = 1;
	rep (i, 1, Max+1) {
		ll cur = num[i];
		ll bef = num[i - 1];

		ans *= mod_pow(mod_pow(2, bef,MODU)-1,cur,MODU);
		ans %= MODU;
		ans *= mod_pow(2, cur*(cur - 1)/2, MODU);

		ans %= MODU;
	}

	printf("%lld\n", ans);
	return 0;
}