#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define FOR(i,a,b) for (lli i=(a);i<(b);i++)
#define REP(i,n) for (lli i=0;i<(n);i++)
#define rep(i,n) for (lli i=0;i<(n);i++)

#define INF LONG_MAX/3
#define PB push_back
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pll pair<lli,lli>
//#define vector<lli> vl
int main(){
  lli N;
  lli R[1000];
  double ans=0;

  cin>>N;
  rep(i,N)
    cin>>R[i];

  sort(R,R+N,greater<lli>());

  rep(i,N){
    ans+=R[i]*R[i]*pow(-1,i);
  }
  ans*=M_PI;

  printf("%30.30f\n",ans);
  
  return 0;
}
