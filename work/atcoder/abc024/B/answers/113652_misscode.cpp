#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF -1145141919810
#define REP(i,n) for (int i=0;i<(n);i++)
typedef pair<int,int> P;

signed main(){
  int N,T,a[100001]={}; cin>>N>>T;
  int tmp,ans=0;
  REP(i,N) cin>>a[i];
  REP(i,N+1){
    if(i==0) tmp=a[i];
    else if(i==N){
      ans+=a[i-1]+T-tmp;
    }
    else{
      if(a[i]>a[i-1]+T){
        ans+=a[i-1]+T-tmp;
        tmp=a[i];
      }
    }
  }

  cout<<ans<<endl;
}
