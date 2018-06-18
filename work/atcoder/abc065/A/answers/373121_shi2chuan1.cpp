#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MP make_pair
using ll = long long;
using namespace std;

int main()
{
  ll x,a,b;
  cin >> x >> a >> b;
  if(b <= a)
    cout << "delicious" << endl;
  else if(b <= a+x)
    cout << "safe" << endl;
  else
    cout << "dangerous" << endl;
  return 0;
}
