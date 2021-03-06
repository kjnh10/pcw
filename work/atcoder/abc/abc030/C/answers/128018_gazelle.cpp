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
	ll N, M;
	ll X, Y;
	CIN2(N, M);
	CIN2(X, Y);
	vector<ll> a(N);
	vector<ll> b(M);
	REP(i, N) {
		CIN(a[i]);
	}
	REP(i, M) {
		CIN(b[i]);
	}
	ll nt = 0;
	ll c = 0;
	bool f = true;
	while(true) {
		if(f) {
			if(a[N - 1] >= nt) {
				nt = *lower_bound(ALL(a), nt) + X;
				++c;
				f = false;
			} else {
				break;
			}
		}
		else {
			if(b[M - 1] >= nt) {
				nt = *lower_bound(ALL(b), nt) + Y;
				++c;
				f = true;
			} else {
				break;
			}
		}
	}
	COUT(c / 2);
}


