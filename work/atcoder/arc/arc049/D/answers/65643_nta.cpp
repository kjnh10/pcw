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

typedef pair<double, double> Seg1D;

inline Seg1D intersectSeg1D(const Seg1D &a, const Seg1D &b) {
	return Seg1D(max(a.first, b.first), min(a.second, b.second));
}
inline double lengthSeg1D(const Seg1D &a) {
	if(a.first >= a.second) return 0;
	else return a.second - a.first;
}

typedef pair<Seg1D, Seg1D> Seg2D;

inline Seg2D intersectSeg2D(const Seg2D &a, const Seg2D &b) {
	return Seg2D(intersectSeg1D(a.first, b.first), intersectSeg1D(a.second, b.second));
}
inline double lengthSeg2D(const Seg2D &a) {
	return (double)lengthSeg1D(a.first) * lengthSeg1D(a.second);
}

int main() {
	int N;
	while(~scanf("%d", &N)) {
		vi x(N), y(N), c(N);
		rep(i, N)
			scanf("%d%d%d", &x[i], &y[i], &c[i]);
		double l = 0, u = 2e8;
		rep(ii, 100) {
			double mid = (l + u) / 2;
			Seg2D rect(Seg1D(-1e5, 1e5), Seg1D(-1e5, 1e5));
			rep(i, N) {
				double t = mid / c[i];
				Seg2D range(Seg1D(x[i] - t, x[i] + t), Seg1D(y[i] - t, y[i] + t));
				rect = intersectSeg2D(rect, range);
			}
			if(lengthSeg2D(rect) > 0)
				u = mid;
			else
				l = mid;
		}
		printf("%.10f\n", u);
	}
	return 0;
}
