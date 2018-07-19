#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

#define DUMP(x) cout<<#x<<":"<<(x)<<endl
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class T>
istream& operator>>(istream& is, vector<T>& xs){
  for(auto& x: xs)
	is >> x;
  return is;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& xs){
  for(unsigned int i=0;i<xs.size();++i)
	os << (i?" ":"") << xs[i];
  return os;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

const int INF = 1e9;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1,0};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;
  VS vs(H);
  cin >> vs;

  int ws = 0;
  REP(y,H) REP(x,W) if(vs[y][x] == '.') ++ws;

  queue<PII> q;
  VVI dist(H, VI(W, INF));
  q.push(MP(0,0));
  dist[0][0] = 0;
  while(!q.empty()){
	auto p = q.front();
	q.pop();

	REP(d,4){
	  PII np(p.FF+dx[d], p.SS+dy[d]);
	  if(np.FF < 0 || H <= np.FF || np.SS < 0 || W <= np.SS || vs[np.FF][np.SS] == '#' || dist[np.FF][np.SS] < INF)
		continue;
	  q.push(np);
	  dist[np.FF][np.SS] = dist[p.FF][p.SS] + 1;
	}
  }

  if(dist[H-1][W-1] == INF) cout << -1 << endl;
  else cout << ws - dist[H-1][W-1] - 1 << endl;

  return 0;
}
