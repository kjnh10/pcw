#include <iostream>
#include <algorithm>

int main() {
  int n, m;

  std::cin >> n >> m;

  std::cout << std::min(m - 1, n - m) << std::endl;
}