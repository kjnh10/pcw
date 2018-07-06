#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
  int N, a[100000], b[100000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    b[i] = i + 1;
  }
  sort(b, b + N, [&](int x, int y) {
      return(a[x - 1] > a[y - 1]);
    });
  for(int i = 0; i < N; i++) {
    cout << b[i] << endl;
  }
}
