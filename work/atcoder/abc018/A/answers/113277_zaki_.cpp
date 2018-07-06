#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a[3];
  int ma=-1,mi=1000;
  for(int i=0;i<3;i++){
      cin>>a[i];
      ma=max(ma,a[i]);
      mi=min(mi,a[i]);
  }
  for(int i=0;i<3;i++){
      if(a[i]==ma) cout<<1<<endl;
      else if(a[i]==mi) cout<<3<<endl;
      else cout<<2<<endl;
  }
}