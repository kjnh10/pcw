#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

int n,a[100010];

int main() {
  cin >> n;
  rep(i,n) {
    cin >> a[i];
    while( a[i] % 2 == 0 ) a[i] /= 2;
  }
  set<int> S;
  rep(i,n) S.insert(a[i]);
  cout << (int)S.size() << endl;
  return 0;
}
