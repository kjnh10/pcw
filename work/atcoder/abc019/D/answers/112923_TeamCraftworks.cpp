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
  int n,v;
  cin >> n;
  vector<int> dist1;
  dist1.push_back(0);
  REP(i,1,n) {
    cout << "? 1 " << i+1 << endl;
    cin >> v;
    dist1.push_back(v);
  }
  int next_sp = 0;
  REP(i,1,n) {
    if( dist1[next_sp] < dist1[i] ) next_sp = i;
  }
  int maxi = 0;
  rep(i,n) {
    if( i != next_sp ) {
      cout << "? " << next_sp+1 << " " << i+1 << endl;
      cin >> v;
      maxi = max(maxi,v);
    }
  }
  cout << "! " << maxi << endl;
  return 0;
}
