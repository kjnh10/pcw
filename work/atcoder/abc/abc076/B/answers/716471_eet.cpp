#include<bits/stdc++.h>
using namespace std;
using Int = long long;
int n,k,ans=1e9;
void dfs(int i,int x){
  if(i==n){
    ans=min(ans,x);
    return;
  }
  dfs(i+1,x+k);
  dfs(i+1,x*2);
}
signed main(){
  cin>>n>>k;
  dfs(0,1);
  cout<<ans<<endl;
  return 0;
}
