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

const int MAX = 1e5+100;
int num[MAX];
bool isp[MAX];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  fill(isp, isp+MAX, true);
  isp[0] = isp[1] = false;
  for(int i=2;i<MAX;++i)
	if(isp[i])
	  for(int j=i+i;j<MAX;j+=i)
		isp[j] = false;

  for(int i=1;i<MAX;i+=2){
	if(isp[i] && isp[(i+1)/2])
	  ++num[i];
	num[i] += num[i-2];
  }

  int Q;
  cin >> Q;
  while(Q--){
	int l, r;
	cin >> l >> r;
	cout << num[r] - num[max(1,l-2)] << endl;
  }

  return 0;
}
