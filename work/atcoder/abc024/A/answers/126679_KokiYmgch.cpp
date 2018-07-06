#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <chrono>

using namespace std;

static const int INF = 1 << 28;
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};
static const int  MOD = 1000000007;

#define D(x) cout << x << endl
#define d(x) cout << x

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int main() { 

  int a, b, c, k, s, t;
  cin >> a >> b >> c >> k >> s >> t;

  D(a * s + b * t - (s + t >= k ? c * (s + t) : 0));
  
  return 0;
}
