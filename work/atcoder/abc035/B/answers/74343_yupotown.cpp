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

int main(int argc, char **argv) {
	string S;
	int T;
	cin >> S >> T;
	int x = 0, y = 0;
	int q = 0;
	REP(i, S.length()) {
		switch (S[i]) {
		case 'L': --x; break;
		case 'R': ++x; break;
		case 'U': ++y; break;
		case 'D': --y; break;
		case '?': ++q; break;
		}
	}
	int d = ABS(x) + ABS(y);
	if (T == 1)
	{
		// max
		cout << (d + q) << endl;
	}
	else
	{
		// min
		if (d >= q)
		{
			cout << (d - q) << endl;
		}
		else
		{
			cout << ((q - d) % 2) << endl;
		}
	}
	return 0;
}
