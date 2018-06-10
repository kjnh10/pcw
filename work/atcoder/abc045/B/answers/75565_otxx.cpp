#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int main() {

  string s[3]; rep(i, 3) cin >> s[i];
  int idx[3] = {};
  int curr = 0;
  while(1) {
    curr = s[curr][idx[curr]++] - 'a';
    if(idx[curr] >= s[curr].size()) {
      cout << char('A' + curr) << endl;
      return 0;
    }
  }
  
  return 0;
}