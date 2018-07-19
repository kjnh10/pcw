#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, L;
string s;
int main() {
  cin >> N >> L >> s;
  int c = 0, r = 1;
  for (int i=0; i<N; i++) {
    if (s[i] == '+') {
      r++;
      if (r > L) {
        r = 1;
        c++;
      }
    }
    else r--;
  }
  cout << c << "\n";
  return 0;
}
