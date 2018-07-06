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
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define REEP(i, N) for(ll i = N - 1; i >= 0; --i)
#define ALL(a) (a).begin(),(a).end()
#define FOR(i,m,n) for(ll i = m; i < n; ++i)
#define RFOR(i,m,n) for(ll i = n - 1; i >= m; --i)
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
	int R, C, K;
	CIN3(R, C, K);
	vector<vector<int> > v(R, vector<int>(C, -INF));
	vector<vector<char> > m(R, vector<char>(C));
	int ans = 0;
	REP(i, R) {
		REP(j, C) {
			CIN(m[i][j]);
		}
	}
	for(int i = K - 1; i <= R - K; ++i) {
		for(int j = K - 1; j <= C - K; ++j) {
			bool f = true;
			for(int k = 0; k <= K - 1; ++k) {
				if(v[i][j + k] == -INF) {
					int c = -1;
					for(int l = 0; l <= K - 1; ++l) {
						if(m[i + l][j + k] == 'o' && m[i - l][j + k] == 'o') {
							c = l;
						} else break;
					}
					v[i][j + k] = c;
				}
				if(v[i][j + k] < K - k - 1) {
					f = false;
					break;
				}
				if(v[i][j - k] == -INF) {
					int c = -1;
					for(int l = 0; l <= K - 1; ++l) {
						if(m[i + l][j - k] == 'o' && m[i - l][j - k] == 'o') {
							c = l;
						} else break;
					}
					v[i][j - k] = c;
				}
				if(v[i][j - k] < K - k - 1) {
					f = false;
					break;
				}
			}
			if(f) ++ans;
		}
	}
	COUT(ans);
}

