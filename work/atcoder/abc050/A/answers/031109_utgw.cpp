#include<bits/stdc++.h>
#define FOR(i,m,n) for(int i=m;i<(n);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int main(void){
  int a, b;
  char c;
  cin >> a >> c >> b;
  if (c == '+')
    cout << a + b << endl;
  else
    cout << a - b << endl;
  return 0;
}
