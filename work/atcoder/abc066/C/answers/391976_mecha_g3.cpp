#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

int main() {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  list<int> b;
  rep(i, n) {
    if (i % 2 == 0) {
      b.push_back(a[i]);
    } else {
      b.push_front(a[i]);
    }
  }

  int i = 0;
  if (n % 2 == 1) {
    reverse(all(b));
  }

  for(int k : b) {
    i++;
    cout << k;
    if (i == n) cout << endl;
    else cout << " ";
  }


  return 0;
}
