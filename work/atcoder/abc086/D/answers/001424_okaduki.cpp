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

LL N, K;
int bb[4010][4010];
int ww[4010][4010];

int bacc[4010][4010];
int wacc[4010][4010];
int bsum(int x1, int y1, int x2, int y2){
  return bacc[y2][x2] - bacc[y2][x1] - bacc[y1][x2] + bacc[y1][x1];
}
int wsum(int x1, int y1, int x2, int y2){
  return wacc[y2][x2] - wacc[y2][x1] - wacc[y1][x2] + wacc[y1][x1];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;

  int K2 = K * 2;
  REP(i,N){
	int x, y;
	char c;
	cin >> x >> y >> c;
	x %= K2;
	y %= K2;
	if(c == 'B'){
	  bb[y][x]++;
	  bb[y+K2][x]++;
	  bb[y][x+K2]++;
	  bb[y+K2][x+K2]++;
	}
	else{
	  ww[y][x]++;
	  ww[y+K2][x]++;
	  ww[y][x+K2]++;
	  ww[y+K2][x+K2]++;
	}
  }

  REP(y,K2*2) REP(x,K2*2){
	bacc[y+1][x+1] += bb[y][x] + bacc[y+1][x] + bacc[y][x+1] - bacc[y][x];
	wacc[y+1][x+1] += ww[y][x] + wacc[y+1][x] + wacc[y][x+1] - wacc[y][x];
  }

  int ans = 0;
  REP(y1,K2) REP(x1,K2){
	int x2 = x1 + K, y2 = y1 + K;
	int sum = bsum(x1, y1, x2, y2) + bsum(x2, y2, x2+K, y2+K);
	sum += wsum(x2, y1, x2+K, y2) + wsum(x1, y2, x2, y2+K);

	//cout<<x1<<","<<y1<<":"<<sum<<endl;
	maxi(ans, sum);
  }
  cout << ans << endl;

  return 0;
}
