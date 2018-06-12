#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
vector<double> x,y,r;
double sq(double a){
  return a*a;
}
double d(in u, in v){
  double s=sqrt(sq(x[u]-x[v])+sq(y[u]-y[v]));
  if(s<r[u]+r[v])
    return 0;
  return s-r[u]-r[v];
}
vector<double> mnd;
const double inf=1e18;
priority_queue<pair<double,in> > q;
VI vis;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  double xs,ys,xt,yt;
  cin>>xs>>ys>>xt>>yt;
  in n;
  cin>>n;
  x.resize(n+2);
  y.resize(n+2);
  r.resize(n+2);
  x[0]=xs;
  y[0]=ys;
  r[0]=0;
  x[1]=xt;
  y[1]=yt;
  r[1]=0;
  forn(z,n)
    cin>>x[z+2]>>y[z+2]>>r[z+2];
  n+=2;
  mnd.resize(n,inf);
  mnd[0]=0;
  q.push(MP(-0,0));
  vis.resize(n,0);
  double u,tu,td;
  while(!q.empty()){
    tie(tu,u)=q.top();
    q.pop();
    tu=-tu;
    if(vis[u])
      continue;
    vis[u]=1;
    forn(i,n){
      td=d(u,i);
      if(tu+td<mnd[i]){
	mnd[i]=tu+td;
	q.push(MP(-(tu+td),i));
      }
    }
  }
  cout<<setprecision(15);
  cout<<mnd[1]<<endl;
  return 0;
}
