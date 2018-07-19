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
  string a, b;
  cin >> a >> b;

  bool flag = true;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) {
      if (a[i] != '@' && b[i] != '@') {
        flag = false;
      } else if (a[i] == '@') {
        if (b[i] != 'a' && b[i] != 't' && b[i] != 'c' && b[i] != 'o' && b[i] != 'd' && b[i] != 'e' && b[i] != 'r') {
          flag = false;
        }
      } else if (b[i] == '@') {
        if (a[i] != 'a' && a[i] != 't' && a[i] != 'c' && a[i] != 'o' && a[i] != 'd' && a[i] != 'e' && a[i] != 'r') {
          flag = false;
        }
      }
    }
  }

  if (flag) {
    D("You can win");
    return 0;
  } else {
    D("You will lose");
    return 0;
  }
}
