#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int T[2][1<<18];
const int ADD = 1<<17;

void update(int c, int x, int v) {
	x += ADD; T[c][x] = v; x >>= 1;
	while(x) {
		T[c][x] = min(T[c][x<<1], T[c][x<<1|1]);
		x >>= 1;
	}
}

int read(int c, int l, int r) {
	int res = 1e9;
	l += ADD, r += ADD;
	while(l <= r) {
		if(l & 1) res = min(res, T[c][l++]);
		if(!(r & 1)) res = min(res, T[c][r--]);
		l >>= 1, r >>= 1;
	}
	return res;
}

int n, A[200020];
int rev[200020];

int read_odd(int l, int r) {
	if(l % 2 == 0) ++l;
	if(r % 2 == 0) --r;
	return read(1, (l+1) / 2, (r+1) / 2);
}

int read_even(int l,int r) {
	if(l % 2) ++l;
	if(r % 2) --r;
	return read(0, (l+1) / 2, (r+1) / 2);
}

pii get(int l, int r) {
	if(l % 2 == 0) {
		int t = read_odd(l+1, r-1);
		int v = rev[t];
		int u = read_even(v+1, r-1);
		return pii(t, u);
	}
	else {
		int t = read_even(l+1, r-1);
		int v = rev[t];
		int u = read_odd(v+1, r-1);
		return pii(t, u);
	}
}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", A+i), rev[A[i]] = i;
	for(int i=1;i<=n;i++) update(i&1, (i+1)/2, A[i]);
	priority_queue <pair<pii, pii>, vector <pair<pii, pii> >, greater<pair<pii, pii> > > T;
	T.push(make_pair(get(0, n+1), pii(0, n+1)));
	rep(i, n/2) {
		auto X = T.top(); T.pop();
		pii a = X.Fi, b = X.Se;
		printf("%d %d ", a.Fi, a.Se);
		int c = rev[a.Fi], d = rev[a.Se];
		if(b.Fi + 1 < c) T.push(make_pair(get(b.Fi, c), pii(b.Fi, c)));
		if(c+1 < d) T.push(make_pair(get(c, d), pii(c, d)));
		if(d+1 < b.Se) T.push(make_pair(get(d, b.Se), pii(d, b.Se)));
	}
}

int main(){
	int T = 1; //scanf("%d", &T);
	while(T--) {
		solve();
	}
	
	return 0;
}
