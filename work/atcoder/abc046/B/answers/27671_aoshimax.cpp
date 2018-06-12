#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  int ans=K;
  for( int i = 1 ; i < N; i++ ){
      ans*=(K-1);
  }
  cout << ans<<endl;
  return 0;
}
