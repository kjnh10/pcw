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
#define pi 3.14159265358979
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define rer(i, l, r) for (int (i) = (int)(l); (i) <= (int)(r); (i)++)
#define reu(i, l, r) for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define D(x) cout << x << endl
#define d(x) cout << x
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x, y) make_pair((x), (y))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

int a[10];

int main() { 
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a[0]++;
    } else if (s[i] == 'B') {
      a[1]++;
    } else if (s[i] == 'C') {
      a[2]++;
    } else if (s[i] == 'D') {
      a[3]++;
    } else if (s[i] == 'E') {
      a[4]++;
    } else if (s[i] == 'F') {
      a[5]++;
    }
  }
  //for (int i = 0; i < 6; i++) {
  //  if (i < 5) {
  //    d(a[i] << " ");
  //  } else {
  //    D(a[i]);
  //  }              
  //}
  
  cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << endl;
  return 0;
}
