#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

const ll size = 100000;
ll N, A[size], distNum[size], maximum;

void init() {
  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> A[i];
    distNum[A[i]] += 1;
    maximum = max(maximum, A[i]);
  }
  
}

ll combination2(ll a) {
  ll ret = a * (a - 1) / 2;
  return ret;
}

ll power(ll a, ll b) {
  ll ret = 1;
  ll temp = a;
  while(b > 0) {
    if(b % 2 == 1)
      ret = ret * temp % MOD;
    b /= 2;
    temp = temp * temp % MOD;
  }

  return ret;
}

ll solve() {
  if(A[0] != 0) {
    return 0;
  }
  
  if(distNum[0] != 1) {
    return 0;
  }

  for(ll i = 1; i <= maximum; i++) {
    if(distNum[i] == 0){
      return 0;
    }
      
  }
  
  ll ret = 1;
  
  for(ll i = 1; i <= maximum; i++) {
    ll pathToParent = power(power(2, distNum[i - 1]) - 1, distNum[i]);
    ll pathToBrothers = power(2, combination2(distNum[i]) );
    ret = ret * pathToParent % MOD;
    ret = ret * pathToBrothers % MOD;

  }

  return ret;

}

int main() {
  init();
  cout << solve() << endl;
}
