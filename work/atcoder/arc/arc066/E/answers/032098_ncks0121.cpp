#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 100500;

int N;
int A[N_]; ll S[N_];
char op[N_];

ll ans;

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N-1; i++) {
    char s[2];
    scanf("%d%s", &A[i], s);
    S[i] = S[i-1] + A[i];
    op[i] = *s;
  }
  scanf("%d", &A[N]);
  S[N] = S[N-1] + A[N];

  int j = N;
  for(int i = N-1; i > 0; i--) {
    if(op[i] == '+') {
      ans += A[i+1];
    }else {
      ans = max(ans, S[N] + S[i+1] - 2 * S[j]) - A[i+1];
      j = i;
    }
  }

  ans += A[1];
  printf("%lld\n", ans);
  return 0;
}
