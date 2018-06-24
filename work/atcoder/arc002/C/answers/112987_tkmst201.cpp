#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <cassert>
#include <sstream>
 
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef complex<double> P;
typedef complex<double> Vec;
typedef pair<int, int> pii;
typedef pair<int, pii> p;
 
#define INF (1<<29)
#define INFL (1ll<<60)
#define EPS (1e-10)
#define PI (acos(-1))
const ll MOD = 1000000007ll;

int main() {
	int n;
	string cmd;
	cin >> n >> cmd;
	
	int ans = INF;
	
	string bt = "ABXY";
	REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4) {
		string L = "", R = "";
		L += bt[i]; L += bt[j];
		R += bt[k]; R += bt[l];
		
		int cnt = 0;
		REP(m, n) {
			string sb = "";
			if (m < n - 1) sb = cmd.substr(m, 2);
			if (sb == L || sb == R) m++;
			cnt++;
		}
		chmin(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}