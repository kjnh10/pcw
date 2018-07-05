#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if (b>a) swap(a,b);
  if (b==0) return a;
  return gcd(b, a%b);
}

int lcd(int a, int b){
  return (a/gcd(a,b))*b;  // overflowしにくいように最初に割り算をする。
}
