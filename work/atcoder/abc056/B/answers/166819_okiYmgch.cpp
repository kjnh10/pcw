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
#include <sstream>
#include <iomanip>
#define INF 1 << 30
#define MOD 1000000007;
#define D(x) cout << x << endl
#define d(x) cout << x
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x) make_pair(x)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

int main() { 
  int w, a, b;
  cin >> w >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  D(max(0, b - a - w));
  return 0;
}

