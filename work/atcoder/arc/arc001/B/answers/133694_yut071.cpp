#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<numeric>
#include<queue>
#include<string>
#include<sstream>

using namespace std;


int main(void) {

  int a, b;
  cin >> a >> b;
  int cnt = 0;
  while( a != b ){
    if( abs(a-b) >= 8 ){
      if( a > b ) a -= 10;
      else a += 10;
    }else if( abs(a-b) >= 4 ){
      if( a > b ) a -= 5;
      else a += 5;
    }else{
      if( a > b ) a -= 1;
      else a += 1;
    }
    cnt++;
    cerr << a << endl;
  }
  cout << cnt << endl;

  return 0;
}










//
