#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;cin>>n;
  std::vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  int res=0;
  for(int i=0;i<n;i++){
      if(i%2==0) res+=v[n-1-i];
  }
  cout<<res<<endl;
}
