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
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	int y, m, d;
	cin>>y;cin.ignore();
	cin>>m;cin.ignore();
	cin>>d;
	while(y % (m * d) != 0) {
		switch(m) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if(d < 31) ++d;
				else {
					if(m != 12) {
						++m;
					} else {
						++y;
						m = 1;
					}
					d = 1;
				}
				break;
			case 4: case 6: case 9: case 11:
				if(d < 30) ++d;
				else {
					++m;
					d = 1;
				}
				break;
			case 2:
				bool uru = false;
				if(y % 400 == 0) uru = true;
				else if(y % 100 == 0) uru = false;
				else if(y % 4 == 0) uru = true;
				if(uru) {
					if(d < 29) ++d;
					else {
						++m;
						d = 1;
					}
				} else {
					if(d < 28) ++d;
					else {
						++m;
						d = 1;
					}
				}
				break;
		}
	}
	cout<<y<<'/'<<setw(2)<<setfill('0')<<m<<'/'<<setw(2)<<setfill('0')<<d<<endl;
}

