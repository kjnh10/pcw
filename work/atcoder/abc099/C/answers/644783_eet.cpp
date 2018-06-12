#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 114514;
Int dp[MAX*2];
signed main(){
  const Int INF = 1e9;
  for(Int i=0;i<MAX*2;i++) dp[i]=INF;
  dp[0]=0;
  vector<Int> v;
  for(Int k=1;k<MAX;k*=6) v.emplace_back(k);
  for(Int k=1;k<MAX;k*=9) v.emplace_back(k);
  for(Int k:v)
    for(Int i=0;i<MAX;i++)
      chmin(dp[i+k],dp[i]+1);
  
  Int n;
  cin>>n;
  cout<<dp[n]<<endl;
  return 0;
}
