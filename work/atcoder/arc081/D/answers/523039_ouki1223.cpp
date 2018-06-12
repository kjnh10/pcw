#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mt make_tuple
#define INF 2000000000
#define INFL 1000000000000000000LL
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<P> vP;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<P> > vvP;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<P, vector<P>, greater<P> > pqlP;
/*
// シンプルな構文解析用
typedef string::const_iterator State;
class ParseError {};
//*/
struct Edge {
	int from, to, cost;
	bool operator<(Edge e) {
		return cost < e.cost;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;



int main(void) {
	int N;
	cin >> N;
	string s, t;
	cin >> s >> t;
	ll ans = 1;
	int start = 0;
	if (s[0] == t[0]) {
		ans = 3;
		start = 1;
	}
	else {
		ans = 6;
		start = 2;
	}
	repl(i, start, N) {
		if (s[i] == t[i]) {
			if (s[i - 1] == t[i - 1]) {
				ans *= 2;
				ans %= MOD;
			}

		}
		else {
			if (s[i - 1] == t[i - 1]) {
				ans *= 2;
				ans %= MOD;
			}
			else {
				ans *= 3;
				ans %= MOD;
			}
			i++;
		}
	}
	cout << ans << endl;

	return 0;
}