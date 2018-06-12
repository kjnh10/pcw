#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
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
#define CEIL(c, a, b) if(a % b == 0) { c = a / b;} else { c = a / b + 1;}
#define sp(n) setprecision(n)
#define INF 1000000000
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll kai(int n, int k) {
	if(k == 0) return 1;
	else return (n * kai(n - 1, k - 1)) % MOD;
}

int main() {
	int N;
	CIN(N);
	ll pena = 0;
	ll baai = 1;
	vector<int> v(N);
	REP(i, N) {
		CIN(v[i]);
	}
	sort(ALL(v));
	int res = 0;
	REP(i, N) {
		pena += v[i] * (N - i);
		if(i == 0) {
			continue;
		} else if(res == 0 && v[i - 1] == v[i]) {
			res = 2;
		} else if(res != 0 && v[i - 1] == v[i]) {
			++res;
		} else if(res != 0 && v[i - 1] != v[i]) {
			baai = (baai * kai(res, res)) % MOD;
			res = 0;
		}
		if(i == N - 1) {
			baai = (baai * kai(res, res)) % MOD;
		}
	}
	COUT(pena);
	COUT(baai);
}
