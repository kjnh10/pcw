#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,b,a) for (int i = (int)(b) - 1; i >= a; --i)
#define REP(i,N) FOR(i,0,N)
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL;

int A[322222];
LL pref[322222], suf[322222];

int main() {
  int N;
  scanf("%d", &N);
  REP(i,3*N) scanf("%d", &A[i]);

  LL su = 0;
  multiset<int> S;
  REP(i,3*N) {
    su += A[i];
    S.insert(A[i]);
    if (S.size() > N) {
      su -= *S.begin();
      S.erase(S.begin());
    }
    pref[i] = su;
  }

  S.clear();
  su = 0;
  FORD(i,3*N,0) {
    su += A[i];
    S.insert(A[i]);
    if (S.size() > N) {
      su -= *S.rbegin();
      S.erase(--S.end());
    }
    suf[i] = su;
  }

  LL best = -1e18;
  FOR(i,N-1,2*N) {
    best = max(best, pref[i] - suf[i+1]);
  }
  printf("%lld\n", best);
}
