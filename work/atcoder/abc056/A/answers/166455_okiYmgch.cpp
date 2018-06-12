#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

static const int INF = 1 << 28;
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

#define MOD 1000000007
#define D(x) cout << x << endl
#define d(x) cout << x

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int main() { 
  char a, b;
  cin >> a >> b;
  if (a == b) {
    D('H');
  } else {
    D('D');
  }
  return 0;
}
