#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  ll t[n];
  for(ll i=0;i<n;i++) cin>>t[i];
  map<ll,ll> m;
  for(ll i=0;i<n;i++) m[t[i]]++;
  ll ans=0,tm=0,com=1,MOD=1000000007LL;
  for(auto i:m){
    ll r=1;
    for(ll j=0;j<i.second;j++){
      tm+=i.first;
      ans+=tm;
      (r*=j+1)%=MOD;;
    }
    (com*=r)%=MOD;
  }
  cout<<ans<<endl<<com<<endl;
  return 0;
}
