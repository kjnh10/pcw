#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

typedef long long ll;
const int nax = 1e5 + 5;
ll t[nax];

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i) scanf("%lld", &t[i]);
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(t[i] > x) {
			ans += t[i] - x;
			t[i] = x;
		}
		if(t[i-1] + t[i] > x) {
			ans += t[i-1] + t[i] - x;
			t[i] = x - t[i-1];
		}
	}
	printf("%lld\n", ans);
}
