#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

typedef pair<int, int> pii;

int n, m;
int a[1000], b[1000], c[1000];
int d[100][100];

#define INF (10000000)

int main(int argc, char **argv) {
	cin >> n >> m;
	REP(i, n) REP(j, n) d[i][j] = INF;
	REP(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		--a[i]; --b[i];
		d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
	}
	REP(k, n) REP(i, n) REP(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int res = 0;
	REP(i, m) {
		if (d[a[i]][b[i]] != c[i]) ++res;
	}
	cout << res << endl;
	return 0;
}
