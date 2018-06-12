#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=MOD-1)+=MOD-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
vector<ll> fact,finv,inv;
ll comb(ll n,ll r){
  if(n<r||r<0)return 0;
  return fact[n]*finv[n-r]%MOD*finv[r]%MOD;
}
class Doralion{
  void Modinvs(vector<ll> &re,int n){
    re.resize(n+1); re[1]=1;
    for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i)%MOD;
  }
  void Facts(vector<ll> &re,int n){
    re.resize(n+1); re[0]=1;
    rep(i,n)re[i+1]=re[i]*(i+1)%MOD;
  }
  void Factinvs(vector<ll> &re,const vector<ll> &inv,int n){
    re.resize(n+1); re[0]=1;
    rep(i,n)re[i+1]=re[i]*inv[i+1]%MOD;
  }
public:
  Doralion(int n){
    Modinvs(inv,n);
    Facts(fact,n);
    Factinvs(finv,inv,n);
  }
} doralion(21234);


ll dp[3123][3123];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  vector<pii> ps;
  rep(i,m){
    int x,y;
    cin>>x>>y; --x;
    if(ps.size() && ps.back().Y>y) continue;
    if(ps.size() && ps.back().X==x) MX(ps.back().Y,y);
    else ps.eb(x,y);
  }
  m=ps.size();
  //cout<<ps;
  vector<int> sum(n+1);
  rep(i,n) sum[i+1]=sum[i]+(s[i]=='1');
  //cout<<sum;
  int prev=0;
  dp[0][0]=1;
  rep(i,m){
    const int l=ps[i].X;
    const int r=ps[i].Y;
    if(prev<l){
      rep(j,n) dp[l][j+sum[l]-sum[prev]]=dp[prev][j];
    }
    int nxt=r;
    if(i+1<m) MN(nxt,ps[i+1].X);
    rep(j,nxt-l+1){
      const ll tmp=comb(nxt-l,j);
      rep(k,n){
	if(k+j>sum[r]) break;
	if(nxt-(k+j)>r-sum[r]) continue;
	(dp[nxt][k+j]+=dp[l][k]*tmp%MOD)%=MOD;
      }
    }
    prev=nxt;
  }
  //rep(i,n+1){rep(j,n+1)cout<<dp[i][j]<<",";cout<<endl;}
  cout<<dp[prev][sum[prev]]<<endl;
  return 0;
}
