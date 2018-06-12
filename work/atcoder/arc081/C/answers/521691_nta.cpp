#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int N;
	while (~scanf("%d", &N)) {
		vector<int> A(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &A[i]);
		map<int, int> cnt;
		for (int a : A)
			++ cnt[a];
		ll ans = 0;
		vi v;
		for (auto p : cnt) {
			if (p.second >= 4)
				amax(ans, (ll)p.first * p.first);
			if (p.second >= 2)
				v.push_back(p.first);
		}
		if (v.size() >= 2)
			amax(ans, (ll)v[v.size() - 2] * v.back());
		printf("%lld\n", ans);
	}
	return 0;
}
