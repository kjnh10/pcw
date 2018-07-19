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

  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for(int i=0; i<n; i++){
    int tmp;
    cin >> tmp;
    if( tmp == 0 ){
      cout << n << endl;
      return 0;
    }
    s[i] = tmp;
  }

  int l = 0;
  long long int prod = s[0];
  int len = 0;
  if( prod <= k ) len++;
  int tmp = len;

  for(int i=1; i<n; i++){
    prod *= s[i];
    tmp++;
    while( prod > k ){
      if( l >= s.size() || l >= i ) break;
      prod /= s[l];
      l++;
      tmp--;
    }
    // cerr << tmp << endl;
    len = max(tmp, len);
  }

  cout << len << endl;


  return 0;
}










//
