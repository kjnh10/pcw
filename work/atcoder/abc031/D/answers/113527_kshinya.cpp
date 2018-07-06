#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define REP(i, a, n) for(int (i) = (a); (i) < (n); (i)++)
using namespace std;

int K, N;
vector<int> u[50];
string w[50], ans[10];
bool assigned[10];

bool verify(int* len) {
  REP(i, 0, K) assigned[i] = false;
  REP(i, 0, N) {
    int head = 0;
    REP(j, 0, u[i].size()) {
      if(head + len[u[i][j]] > w[i].size()) return false;
      if(!assigned[u[i][j]]) {
        ans[u[i][j]] = w[i].substr(head, len[u[i][j]]);
        assigned[u[i][j]] = true;
      } else if(ans[u[i][j]].compare(w[i].substr(head, len[u[i][j]]))) return false;
      head += len[u[i][j]];
    }
    if(head < w[i].size()) return false;
  }
  return true;
}

int main(void) {
  cin >> K >> N;
  REP(i, 0, N) {
    long v;
    cin >> v >> w[i];
    while(v) u[i].push_back(v % 10 - 1), v /= 10;
    reverse(u[i].begin(), u[i].end());
  }

  long m = pow(3L, (long) K);
  int len[10];
  REP(i, 0, m) {
    int p = i;
    REP(j, 0, K) len[j] = p % 3 + 1, p /= 3;
    if(verify(len)) {
      REP(j, 0, K) cout << ans[j] << endl;
      return 0;
    }
  }

  return 0;
}
