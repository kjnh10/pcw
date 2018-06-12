#include<bits/stdc++.h>
using namespace std;
using Int = long long;
Int m[90];
Int lu(Int i){
  if(~m[i]) return m[i];
  if(i>=2) return m[i]=lu(i-1)+lu(i-2);
  if(i==0) return m[i]=2;
  if(i==1) return m[i]=1;
}
signed main(){
  memset(m,-1,sizeof(m));
  Int n;
  cin>>n;
  cout<<lu(n)<<endl;
  
  return 0;
}
