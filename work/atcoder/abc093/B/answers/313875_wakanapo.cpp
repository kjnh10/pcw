#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  int a, b, k;
  std::cin >> a >> b >> k;
  for (int i = a; i <= b; ++i) {
    if (i < a + k || i > b - k)
      std::cout << i << std::endl;
  }
}
