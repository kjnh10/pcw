#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a,b;cin>>a>>b;
  if(a*b<0) cout<<b-a-1<<endl;
  else cout<<(b-a)<<endl;
}
