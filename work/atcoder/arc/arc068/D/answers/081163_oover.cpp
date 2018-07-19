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

int cnt[111111];
int main() {
  int N;
  scanf("%d", &N);
  REP(i,N) {
    int A;
    scanf("%d", &A);
    ++cnt[A];
  }
  int additional = 0;
  REP(i,111111) additional += max(0, cnt[i] - 1);
  if (additional % 2) ++additional;
  printf("%d\n", N - additional);
}
