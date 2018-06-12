#include <bits/stdc++.h>
#define FOR(x,n) for(int x = 0; x < n; x++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
  int A[3] = {};
  set<int> s;
  FOR(x,3) cin >> A[x], s.insert(A[x]);
  cout << s.size() << "\n";
}