#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
#include<queue>
using namespace std;

long long int powmod(long long int a, long long int b, long long int p){
  if( b == 0 ) return 1;
  if( b%2 == 0 ){
    long long int d = powmod(a, b/2, p);
    return ((d%p) * (d%p)) % p;
  }
  return ( (a%p) * (powmod(a, b-1, p)%p) ) % p;
}

int main(void) {

  long long int mod = 1000000007;

  int w, h;
  cin >> w >> h;
  w--;
  h--;
  long long int tmp = w+h;
  for(int i=w+h-1; i>h; i--){
    tmp *= i;
    tmp %= mod;
  }

  long long int y = w;
  for(int i=w-1; i>0; i--){
    y *= i;
    y %= mod;
  }

  y = powmod(y, mod-2, mod);

  tmp = ((tmp%mod) * (y%mod))%mod;
  cout << tmp << endl;

  return 0;
}



//
