#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF -1145141919810
#define REP(i,n) for (int i=0;i<(n);i++)
typedef pair<int,int> P;

signed main(){
  int a,b,c; cin>>a>>b>>c;
  int ans=0;
  for(int i=0;i<a;i++){
    string t1;
    int t2;
    cin>>t1>>t2;
    if(t2<b) t2=b;
    if(t2>c) t2=c;
    if(t1=="West") ans+=t2;
    else ans-=t2;
  }
  if(ans>0) cout<<"West"<<" ";
  else if(ans<0) cout<<"East"<<" ";
  cout<<abs(ans)<<endl;
}
