#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;cin>>n;
  int sum=0,div=0;
  for(int i=0;i<n;i++){
      int a;cin>>a;
      if(a){sum+=a;div++;}
  }
  cout<<(sum-1)/div+1<<endl;
}
