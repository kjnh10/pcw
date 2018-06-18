#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,d,x;
  cin>>n>>d>>x;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  for(Int i=0;i<n;i++){
    for(Int j=0;j<d;j++)
      if(a[i]*j<d) x++;
  }
  cout<<x<<endl;
  return 0;
}
