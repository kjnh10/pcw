#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,y;
  cin>>n>>y;
  for(Int i=0;i<=n;i++){
    for(Int j=0;i+j<=n;j++){
      Int k=n-(i+j);
      if(i*10000+j*5000+k*1000==y){
	cout<<i<<" "<<j<<" "<<k<<endl;
	return 0;
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
  return 0;
}
