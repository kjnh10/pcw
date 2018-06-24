#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  a.emplace(a.begin(),0);
  a.emplace_back(0);
  Int ans=0;
  for(Int i=1;i<(Int)a.size();i++)
    ans+=abs(a[i]-a[i-1]);
  for(Int i=1;i<=n;i++){
    cout<<ans-(abs(a[i]-a[i-1])+abs(a[i]-a[i+1]))+abs(a[i+1]-a[i-1])<<endl;
  }
  return 0;
}
