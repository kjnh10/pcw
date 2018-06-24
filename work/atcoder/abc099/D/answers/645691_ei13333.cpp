#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, C, V[30][30], c[500][500];

  cin >> N >> C;
  for(int i = 0; i < C; i++) {
    for(int j = 0; j < C; j++) {
      cin >> V[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> c[i][j];
    }
  }


  int64 cost[30][3] = {{}};

  for(int i = 0; i < C; i++) {
    for(int l = 0; l < N; l++) {
      for(int m = 0; m < N; m++) {
        int sum = (l + m) % 3;
        if(sum == 0) cost[i][0] += V[c[l][m] - 1][i];
        else if(sum == 1) cost[i][1] += V[c[l][m] - 1][i];
        else if(sum == 2) cost[i][2] += V[c[l][m] - 1][i];
      }
    }
  }

  int64 all = 1LL << 60;
  for(int i = 0; i < C; i++) {
    for(int j = 0; j < C; j++) {
      for(int k = 0; k < C; k++) {
        if(i == j || i == k || j == k) continue;
        all = min(all, cost[i][0] + cost[j][1] + cost[k][2]);
      }
    }
  }

  cout << all << endl;
}