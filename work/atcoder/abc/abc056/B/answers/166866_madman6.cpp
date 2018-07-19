#include <iostream>
using namespace std;

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (a <= b && b <= a + w) {
    cout << 0 << endl;
    return 0;
  }

  if (a + w < b) {
    cout << b - (a + w) << endl;
  } else {
    cout << a - (b + w) << endl;
  }

  return 0;
}
