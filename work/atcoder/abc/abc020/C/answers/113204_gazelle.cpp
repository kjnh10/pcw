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

int maxx = 0;
int H, W, T;
int map[10][10];
int whitetable[10][10];
int table[10][10];
P S, G;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};


void dfs(P point, int b, int w) {
	if((b == 0 && w > T) || (b != 0 && (T - w) / b <= maxx)) {
		return;
	}
	if((b != 0 && (T - w) / b < table[point.first][point.second]) || (b == 0 && w >= whitetable[point.first][point.second])) {
		return;
	}
	if(point.first == G.first && point.second == G.second) {
		if ((T - w) / b > maxx) {
			maxx = (T - w) / b;
		}
		return;
	}
	if(b != 0) {
		table[point.first][point.second] = (T - w) / b;
	}
	else if(b == 0) {
		whitetable[point.first][point.second] = w;
	}
	REP(i, 4) {
		int nx = point.first + DX[i];
		int ny = point.second + DY[i];
		if(nx >= 0 && nx < H && ny >= 0 && ny < W && (map[nx][ny] == 0 || map[nx][ny] == 1)) {
			if(map[nx][ny] == 0) {
				map[nx][ny] = 2;
				dfs(P(point.first + DX[i], point.second + DY[i]), b , w + 1);
				map[nx][ny] = 0;
			}
			else if(map[nx][ny] == 1) {
				map[nx][ny] = 2;
				dfs(P(point.first + DX[i], point.second + DY[i]), b + 1 , w);
				map[nx][ny] = 1;
			}
		}
	}
	return;
}

int main() {
	REP(i, 10) {
		REP(j, 10) {
			table[i][j] = 0;
			whitetable[i][j] = 1000;
		}
	}
	CIN3(H, W, T);
	REP(i, H) {
		REP(j, W) {
			char s;
			CIN(s);
			if(s == 'S') {
				S.first = i;
				S.second = j;
				map[i][j] = 2;
			} else if(s == 'G') {
				G.first = i;
				G.second = j;
				map[i][j] = 0;
			} else if(s == '.') {
				map[i][j] = 0;
			} else if(s == '#') {
				map[i][j] = 1;
			}
		}
	}
	dfs(P(S.first, S.second), 0, 0);
	COUT(maxx);
}
