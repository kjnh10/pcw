#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int R[N], H[N];

  int table[100001][3];
  int rating[100001];
  int winInRating[100001];
  int loseInRating[100001];
  
  
  for(int i = 0; i < 100001; i++)
    winInRating[i] = loseInRating[i] = rating[i] = 0;


  for(int i = 0; i < 100001; i++) {
    for(int k = 0; k < 3; k++) {
      table[i][k] = 0;
    }
  }

  for(int i = 0; i < N; i++) {
    cin >> R[i] >> H[i];
    H[i] -= 1;
    table[R[i]][H[i]] += 1;
    rating[R[i]] += 1;
  }
  
  int count;
  count = 0;
  for(int i = 0; i < 100001; i++) {
    winInRating[i] = count;
    count += rating[i];
  }
  count = 0;

  for(int i = 100000; i>= 0; i--) {
    loseInRating[i] = count;
    count += rating[i];
  }

  for(int i = 0; i < N; i++) {
    int winAgainst = H[i] + 1;
    int loseAgainst = H[i] + 2;
    winAgainst %= 3;
    loseAgainst %= 3;
    
    cout << winInRating[R[i]] + table[R[i]][winAgainst] << ' ' ;
    cout << loseInRating[R[i]] + table[R[i]][loseAgainst] << ' ';
    cout << table[R[i]][H[i]] - 1 << endl;
  }
  
}
