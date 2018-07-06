#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int res=0;
  for(int i=0;i<3;i++){
      int s,e;cin>>s>>e;
      res+= s*e/10;
  }
  cout<<res<<endl;
}
