#define _CRT_SECURE_NO_WARNINGS
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))
#define ITER(it,a) for(__typeof(a.begin()) it=a.begin();it!=a.end();++it)
#define DBG1(a) cerr<<#a<<" = "<<(a)<<"\n"
#define DBG2(a,b) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define y1 frgrwegreg

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX = 100017;

LL x = 1, y = 1;
LL n, a, b;

int main()
{
	//freopen("C.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i,0,n)
	{
		cin >> a >> b;
		LL d1 = (x+a-1)/a;
		LL d2 = (y+b-1)/b;
		LL d = max(d1,d2);
		x = a*d, y = b*d;
	}
	cout << x + y;
	return 0;
}
