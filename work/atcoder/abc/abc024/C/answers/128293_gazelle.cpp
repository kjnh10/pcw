#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define REP(i, N) for(int i = 0; i < N; ++i)
#define REEP(i, N) for(int i = N - 1; i >= 0; --i)
#define ALL(a) (a).begin(),(a).end()
#define FOR(i,m,n) for(int i = m; i < n; ++i)
#define RFOR(i,m,n) for(int i = n - 1; i >= m; --i)
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a << endl
#define COUT2(a, b) cout << a << " " << b << endl
#define COUT3(a, b, c) cout << a << " " << b << " " << c << endl
#define pb push_back
#define PB push_back
#define VINT(v, n) vector<int> v(n); REP(i, n) { v[i] = 0 }
#define VINT2(v, n, m) vector<vector<int> > v(n, vector<int>(m)); REP(i, n) { REP(j, m) { v[i][j] = 0 } }
#define VCHAR(v, n) vector<char>v(n)
#define KIRIAGE(a, b) a += (b - a % b) % b
#define CEIL(c, a, b) if(a % b == 0) { c = a / b;} else { c = a / b + 1;}
#define sp(n) setprecision(n)
#define INF 1000000000
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	int N, D, K;
	CIN3(N, D, K);
	vector<P> v(D);
	REP(i, D) {
		CIN2(v[i].first, v[i].second);
	}
	REP(i, K) {
		int s, t;
		CIN2(s, t);
		int ans = 0;
		REP(j, D) {
			ans = j;
			if(v[j].first <= s && v[j].second >= s) {
				if(v[j].first <= t && v[j].second >= t) {
					break;
				} else if(v[j].first > t) {
					s = v[j].first;
				} else if(v[j].second < t) {
					s = v[j].second;
				}
			}
		}
		COUT(ans + 1);
	}
}

