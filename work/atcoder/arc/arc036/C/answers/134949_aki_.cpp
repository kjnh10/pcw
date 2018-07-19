#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k;cin>>n>>k;
  int t[n+1];
  cin>>t[1]>>t[2];
  for(int i=3;i<=n;i++){
      cin>>t[i];
      if(t[i-2]+t[i-1]+t[i]<k){
          cout<<i<<endl;
          return 0;
      }
  }
  cout<<-1<<endl;
}
