#include <bits/stdc++.h>

using namespace std;

const int Nmax = 102;
int n, a[3][Nmax], dp[3][Nmax];
int32_t main() {
   //ifstream cin("a.in");
   cin >> n;
   for(int i = 1; i <= 2; ++i)
    for(int j = 1; j <= n; ++j) cin >> a[i][j];
   dp[1][1] = a[1][1];
   for(int i = 1; i <= 2; ++i) {
      for(int j = 1; j <= n; ++j) {
         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
      }
   }
   cout << dp[2][n];
}

