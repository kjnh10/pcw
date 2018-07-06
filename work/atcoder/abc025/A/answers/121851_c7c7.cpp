#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  --n;
  cout << s[n / 5] << s[n % 5] << endl;
}