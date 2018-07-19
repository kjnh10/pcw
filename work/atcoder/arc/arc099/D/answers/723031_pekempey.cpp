#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dsum(long long n) {
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  long long K;
  cin >> K;
  long long x = 1;
  long long p = 1;
  while (K > 0) {
    cout << x << endl;
    K--;
    if (K < 0) break;
    long long nx1 = x + p;
    long long nx2 = x + p * 10;
    if (nx1 * dsum(nx2) <= nx2 * dsum(nx1)) {
      x = nx1;
    } else {
      x = nx2;
      p *= 10;
    }
  }
}