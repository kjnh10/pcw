#include<bits/stdc++.h>
#define FOR(i,m,n) for(int i=m;i<(n);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int main(void){
  int n;
  cin >> n;
  vector<int> T(n);
  REP(i, n)
    cin >> T[i];
  int m;
  cin >> m;
  vector<int> P(m), X(m);
  REP(i, m)
    cin >> P[i] >> X[i];
  REP(i, m) {
    int ans = 0;
    REP(j, n) {
      if (j == P[i] - 1)
        ans += X[i];
      else
        ans += T[j];
    }
    cout << ans << endl;
  }
  return 0;
}
