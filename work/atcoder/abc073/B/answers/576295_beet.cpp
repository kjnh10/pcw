#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a=0;
  while(n--){
    int l,r;
    cin>>l>>r;
    a+=r-l+1;
  }
  cout<<a<<endl;
  return 0;
}
