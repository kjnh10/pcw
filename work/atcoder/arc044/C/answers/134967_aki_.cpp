#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;cin>>n;
  bool prime=true;
  for(ll i=2;i*i<=n;i++) if(n%i==0) prime=false;
  if(n!=1 && (prime || (n%2 && n%3 && n%5))) cout<<"Prime"<<endl;
  else cout<<"Not Prime"<<endl;
}
