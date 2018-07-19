#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n;
  cin>>n;
  vector<Int> d(n);
  for(Int i=0;i<n;i++) cin>>d[i];
  sort(d.begin(),d.end());
  d.erase(unique(d.begin(),d.end()),d.end());
  cout<<d.size()<<endl;
  return 0;
}
