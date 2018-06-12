#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  sort(a.rbegin(),a.rend());
  Int x=0,y=0;
  for(Int i=0;i<n;i++) if(i&1) y+=a[i];else x+=a[i];
  cout<<x-y<<endl;
  return 0;
}
