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
#include <iostream>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);
 
const int K_ = int(1e5), B = 50;
 
int K;
bool vis[K_][B+1];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("d.in", "r", stdin);
#endif
  scanf("%d", &K);

  int ub = 0;
  for(int k = K; k > 0; k /= 10) ub += k % 10;
  
  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.emplace(0, 0);
  vis[0][0] = true;

  while(!pq.empty()) {
    int u, s; tie(s, u) = pq.top(); pq.pop();
    if(u == 0 && s > 0) {
      printf("%d\n", s);
      return 0;
    }
    for(int d = 0; d < 10; d++) {
      int v = (u * 10 + d) % K;
      int t = s + d;
      if(t <= B && !vis[v][t]) {
        vis[v][t] = true;
        pq.emplace(t, v);
      }
    }
  }
  
  return 0;
}