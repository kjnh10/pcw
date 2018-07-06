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

int main() {
  string s;
  cin >> s;
  rep(i,(int)s.size()) {
    cout << s[i];
    int cnt = 1;
    int sp = i;
    while( i+1 < (int)s.size() && s[sp] == s[i+1] ) {
      ++cnt, ++i;
    }
    cout << cnt;
  } puts("");
  return 0;
}
