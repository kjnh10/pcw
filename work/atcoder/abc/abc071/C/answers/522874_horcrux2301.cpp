#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  ll n;
  cin >> n;
  ll arr[n];
  for(ll i=0;i<n;i++)
    cin >> arr[i];
  sort(arr,arr+n,greater<ll>());
  ll i=0;
  ll a1=-1,a2=-1;
  while(i<n){
    if(arr[i]==arr[i+1]){
      if(a1==-1){
        a1=arr[i];
        i+=2;
      }
      else if(a1!=-1){
        a2=arr[i];
        i+=2;
        break;
      }
    }
    else{
      i++;
    }
  }
  if(a1!=-1 && a2!=-1){
    ll ans = a1*a2;
    cout << ans << endl;
  }
  else{
    cout << "0" << endl;
  }
  return 0;
}
