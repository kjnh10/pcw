#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
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
#define pb(v, a) v.push_back(n)
#define VINT(v, n) vector<int> v(n); REP(i, n) { v[i] = 0 }
#define VINT2(v, n, m) vector<vector<int> > v(n, vector<int>(m)); REP(i, n) { REP(j, m) { v[i][j] = 0 } }
#define VCHAR(v, n) vector<char>v(n)
#define MAX(a, b) a > b ? a : b;
#define MIN(a, b) a < b ? a : b;
#define CEIL(c, a, b) if(a % b == 0) { c = a / b;} else { c = a / b + 1;}
#define sp(n) setprecision(n)
#define INF 100000000

using namespace std;
typedef pair<int, int> P;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};



int main() {
	int A, B, C;
	CIN2(A,B);
	if(B < 10) {
		C = A * 10 + B;
	} else if(B < 100) {
		C = A * 100 + B;
	} else {
		C = A * 1000 + B;
	}
	COUT(2 * C);
}
