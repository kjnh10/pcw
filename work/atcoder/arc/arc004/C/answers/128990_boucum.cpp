#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(a < b) swap(a,b);
  if(a%b == 0) return b;

  ll c = a%b;
  return gcd(b,c);
}

bool solve(ll n, ll x, ll y){
  ll d1 = n*(n+1)-((2*n)/y)*x;
  ll d2 = 2*n;

  if(n <= 0 || d1 <= 0 || d2 <= 0) return false;

  ll m = d1/2;
  if(m <= 0 || m > n) return false;

  if(gcd(d2,y) != y) return false;
  if(d1%2 != 0) return false;

  cout << n << " " << m << endl;

  return true;
}

int main(){
  ll x,y;
  scanf("%llu/%llu", &x, &y);

  ll dd = gcd(x,y);
  x /= dd;
  y /= dd;

  ll m = (2.0/y * x -1) -1;


  ll k;
  bool flg = false;
  for(int i=0; i<10; i++){
    if(m <= 0){
      m++;
      continue;
    }

    if(solve(m,x,y)){
      flg = true;
    }
    m++;
  }

  if(!flg){
    cout <<"Impossible" << endl;
  }

  return 0;
}