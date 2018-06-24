#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  puts(n % 10 == 9 || n / 10 == 9 ? "Yes" : "No");
}