#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <fstream>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define FOR(i,a,x) for(int i=(a);i<(x);i++)
#define rep(i,n)	FOR(i,0,n)
#define xFOR(i,a,x) for(int i=(a);i<=(x);i++)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end())
#define ub(vec,a) upper_bound(vec.begin(),vec.end())
#define uniq(vec) vec.erace(unique(vec.begin(),vec.end(),vec.end))
#define mp1(a,b,c) P1(a,P(b,c))
#define all(x) (x).begin(),(x).end()

#define debug(X) cout<<"["<<#X<<"]"<<X<<endl;

inline bool cheak(int x, int y, int xMax, int yMax) { return x >= 0 && y >= 0 && xMax > x && yMax > y; }
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
template<class T> inline T sqr(T x) { return x*x; }

const int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int mod = 1000000007;
const int INF = 1e9;

int gcd(int n, int m) {
	if ((0 == m) || (0 == n)) {
		return 0;
	}
	while (m != n) {
		if (m > n) {
			m = m - n;
		}
		else {
			n = n - m;
		}
	}
	return m;
}

int a, b;
int main() {
	cin >> a >> b;
	int g=gcd(a, b);
	cout << a / g << ":" << b / g << endl;
	return 0;
}
