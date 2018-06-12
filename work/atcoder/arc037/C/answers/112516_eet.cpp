#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    ans+=max(0,80-m);
  }
  cout<<ans<<endl;
  return 0;
}
