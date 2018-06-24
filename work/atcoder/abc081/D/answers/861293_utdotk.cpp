#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int maxA = a[0];
  int maxI = 0;
  int minA = a[0];
  int minI = 0;
  for (int i = 1; i < N; i++) {
    if (a[i] > maxA) {
      maxA = a[i];
      maxI = i;
    }
    if (a[i] < minA) {
      minA = a[i];
      minI = i;
    }
  }

  vector<int> src, dst;
  src.reserve(2 * N);
  dst.reserve(2 * N);
  bool pos = maxA > 0 && maxA > -minA;
  int nA = pos ? maxA : minA;
  int nI = pos ? maxI : minI;
  for (int i = 0; i < N; i++) {
    if (i == nI) {
      continue;
    }
    a[i] += nA;
    src.push_back(nI);
    dst.push_back(i);
  }

  if (pos) {
    for (int i = 1; i < N; i++) {
      a[i] += a[i - 1];
      src.push_back(i - 1);
      dst.push_back(i);
    }
  } else {
    for (int i = N - 2; i >= 0; i--) {
      a[i] += a[i + 1];
      src.push_back(i + 1);
      dst.push_back(i);
    }
  }

  cout << src.size() << endl;
  for (int i = 0; i < src.size(); i++) {
    cout << src[i] + 1 << ' ' << dst[i] + 1 << endl;
  }

  return 0;
}
