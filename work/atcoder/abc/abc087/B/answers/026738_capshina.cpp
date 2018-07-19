#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c, x;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> x;

  int p = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
	if (i * 500 + j * 100 + k * 50 == x)
	  p++;
      }
    }
  }
  cout << p << endl;
}
