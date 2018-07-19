#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k;cin>>n>>k;
  std::vector<double> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end());
  double r=0;
  for(int i=0;i<k;i++){
      r=(r+v[n-k+i])/2;
  }
  cout<<fixed<<setprecision(10)<<r<<endl;
}
