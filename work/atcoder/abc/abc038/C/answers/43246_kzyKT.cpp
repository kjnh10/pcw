#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define mem(a) memset(a,0,sizeof(a))
#define pd(a) printf("%.10f\n",a)
#define pb(a) push_back(a)
#define in(a) insert(a)
#define pi M_PI
#define R cin>>
#define F first
#define S second
#define C class
#define ll long long
#define ln cout<<'\n'
template<C T>void pr(T a){cout<<a;ln;}
template<C T,C T2>void pr(T a,T2 b){cout<<a<<' '<<b;ln;}
template<C T,C T2,C T3>void pr(T a,T2 b,T3 c){cout<<a<<' '<<b<<' '<<c;ln;}
template<C T>void PR(T a,int n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

void Main() {
  int n;
  R n;
  int a[n];
  rep(i,n) R a[i];
  ll l=0;
  ll ans=1;
  for(ll r=1; r<n; r++) {
    if(a[r-1]>=a[r]) l=r;
    ans+=r-l+1;
  }
  pr(ans);
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
