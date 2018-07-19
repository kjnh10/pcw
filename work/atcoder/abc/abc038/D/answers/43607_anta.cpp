#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }


int longestIncreaseSequence(int a[], int n) {
	vector<int> A(n, INF);
	for(int i = 0; i < n; i ++)
		*lower_bound(A.begin(), A.end(), a[i]) = a[i];
	return find(A.begin(), A.end(), INF) - A.begin();
}

int main() {
	int N;
	while(~scanf("%d", &N)) {
		vpii v(N);
		rep(i, N) {
			int w; int h;
			scanf("%d%d", &w, &h);
			v[i] = mp(w, -h);
		}
		sort(all(v));
		vi a(N);
		rep(i, N)
			a[i] = -v[i].second;
		int ans = longestIncreaseSequence(a.data(), a.size());
		printf("%d\n", ans);
	}
	return 0;
}
