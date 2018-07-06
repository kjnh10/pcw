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

  string s;
  cin >> s;
  int cnt = 0;
  bool f = false;
  for(int i=0; i<s.size(); i++){
    if( s[i] == '0' ){
      f = true;
    }
    if( s[i] == '+' ){
      if( !f ) cnt++;
      f = false;
    }
  }
  if( !f ) cnt++;

  cout << cnt << endl;

  return 0;
}










//
