#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
#define mod 1000000007

int n,c;
int d[33][33];
int col[505][505];
int cnt[3][33];

int main(){
  cin>>n>>c;
  rep(i,c)rep(j,c)cin>>d[i][j];
  rep(i,n)rep(j,n){
    cin>>col[i][j];
    col[i][j]--;
  }
  rep(i,n)rep(j,n){
    cnt[(i+j)%3][col[i][j]]++;
  }
  int res=INF;
  rep(x,c)rep(y,c)rep(z,c){
    if(x==y||y==z||z==x)continue;
    int sa=0,sb=0,sc=0;
    rep(i,c){
      if(i!=x)sa+=d[i][x]*cnt[0][i];
    }
    rep(i,c){
      if(i!=y)sb+=d[i][y]*cnt[1][i];
    }
    rep(i,c){
      if(i!=z)sc+=d[i][z]*cnt[2][i];
    }
    minch(res,sa+sb+sc);
  }
  cout<<res<<endl;
  return 0;
}
