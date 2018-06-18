#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }

  
  int a[3];
  int b[3];
  for (a[0] = 0; a[0] <= 100; a[0]++) {
    for (a[1] = 0; a[1] <= 100; a[1]++) {
      for (a[2] = 0; a[2] <= 100; a[2]++) {
        b[0] = c[0][0] - a[0];
        b[1] = c[0][1] - a[0];
        b[2] = c[0][2] - a[0];

        bool all = true;
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            all &= c[i][j] == a[i] + b[j];
          }
        }
        if (all) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
