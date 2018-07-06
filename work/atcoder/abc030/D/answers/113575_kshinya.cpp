#include <iostream>
#include <cstdlib>
#define REP(i, a, n) for(int (i) = (a); (i) <= (n); (i)++)
using namespace std;

int main(void) {
  const int SIZE = 100001;
  int N, a, b[SIZE];
  string k;
  cin >> N >> a >> k;
  REP(i, 1, N) cin >> b[i];

  int s = a, cnt = 0, c[SIZE], d[SIZE];
  bool visited[SIZE];
  REP(i, 1, N) visited[i] = false;
  while(!visited[s]) {
    visited[s] = true;
    d[s] = cnt;
    c[cnt] = s;
    s = b[s];
    cnt++;
  }
  int p = d[s], q = cnt - p;

  int l;
  if(k.size() < 8 && (l = atoi(k.c_str())) < p) {
    cout << c[l] << endl;
  } else {
    int mod = 0;
    REP(i, 0, k.size() - 1) mod = (mod * 10 + (k[i] - '0')) % q;
    mod = (q + mod - p % q) % q;
    cout << c[mod + p] << endl;
  }

  return 0;
}
