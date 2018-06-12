#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int x[N];
  for (int i = 0; i < N; i++) cin >> x[i];

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += min(abs(0 - x[i]) * 2, abs(K - x[i]) * 2);
  }

  cout << ans << endl;

  return 0;
}
