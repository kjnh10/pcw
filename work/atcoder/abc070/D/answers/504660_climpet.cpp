#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }
template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8

VV(pii) G;
vector<LL> dist;

void dfs(int u, LL d){
	if(dist[u] >= 0){ return; }
	dist[u] = d;
	for(cauto p : G[u]){
		dfs(p.first, d + p.second);
	}
}

void mainmain(){
	int n;
	scanf("%d", &n);
	G.resize(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	int q, k;
	scanf("%d%d", &q, &k);
	dist.assign(n + 1, -1);
	dfs(k, 0);
	for(int i = 0; i < q; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		LL ans = dist[x] + dist[y];
		printf("%lld\n", ans);
	}
}



}
int main() try{
//	ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}
catch(...){}
