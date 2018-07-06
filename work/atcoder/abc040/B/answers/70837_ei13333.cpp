#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int ret = 114514;
  for(int i = 1; i <= n; i++) {
    ret = min(ret, abs(i - n / i) + n % i);
  }
  cout << ret << endl;
}

