#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define int long long
#define INF (1LL<<60)

int N;
int A[100000], B[100000];

signed main() {
  cin >> N;
  int al = INF, ar = -INF, bl = INF, br = -INF;
  for (int i=0; i<N; i++) {
    int x, y;
    cin >> x >> y;
    A[i] = x+y;
    B[i] = x-y;
    al = min(al, x+y);
    ar = max(ar, x+y);
    bl = min(bl, x-y);
    br = max(br, x-y);
  }
  int a, b;
  if (ar - al >= br - bl) {
    a = (al+ar) / 2;
    int l = a - al;
    b = min(bl + l, br - l);
    while (true) {
      bool f = true;
      for (int i=0; i<N; i++) {
        if (max(abs(A[i]-a), abs(B[i]-b)) != l) {
          f = false;
          break;
        }
      }
      if (f) break;
      b++;
    }
  }
  else {
    b = (bl+br) / 2;
    int l = b - bl;
    a = min(al + l, ar - l);
    while (true) {
      bool f = true;
      for (int i=0; i<N; i++) {
        if (max(abs(A[i]-a), abs(B[i]-b)) != l) {
          f = false;
          break;
        }
      }
      if (f) break;
      a++;
    }
  }
  cout << (a+b)/2 << " " << (a-b)/2 << "\n";
  return 0;
}
