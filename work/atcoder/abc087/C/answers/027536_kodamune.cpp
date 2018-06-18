#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define pb push_back
using namespace std;
const int INF = 1e9;
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll a[n],b[n];
  REP(i,n){
    cin >> a[i];
  }
  REP(i,n){
    cin >> b[i];
  }
  ll mx = 0;
  REP(i,n){
    ll sum = 0;
    REP(j,i+1){
      sum += a[j];
    }
    for(int k = i;k < n;k++){
      sum += b[k];
    }
    mx = max(mx,sum);
  }
  cout << mx << endl;
  return 0;
}
