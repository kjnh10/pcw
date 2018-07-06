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
  lli a[100];
  lli ans=0,num=0;
  double tmp=0,ave=0;

  cin>>N;
  rep(i,N){
    cin>>a[i];
    ave+=a[i];
  }
  ave/=N;
  if(fmod(ave,1)){
    cout<<-1<<endl;
    return 0;
  }

  rep(i,N){
    tmp+=a[i];
    num++;
    if(tmp/num==ave){
      ans+=num-1;
      tmp=num=0;
    }
  }

  cout<<ans<<endl;
  
  return 0;
}