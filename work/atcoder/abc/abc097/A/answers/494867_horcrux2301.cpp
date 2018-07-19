#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#define ll long long
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pi(n) prllf("%d",n)
#define pl(n) prllf("%d",n)
using namespace std;

int main(){
  int a,b,c,d;
  cin >>a  >> b >> c>> d;
  if(abs(a-c)<=d)
    cout << "Yes" << endl;
  else{
    if(abs(a-b)<=d && abs(c-b)<=d)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
