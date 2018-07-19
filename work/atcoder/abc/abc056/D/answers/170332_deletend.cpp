#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  long long int c[a], d[a];

  for(int i = 0; i < a; i++) {
    cin >> c[i];
    d[i] = 0;
  }

  for(int i = 0; i < a; i++) {
    for(int j = 0; j < a - i - 1; j++) {
      if(c[j] < c[j + 1]) swap(c[j], c[j + 1]);
    }
  }

  for(int i = 0; i < a; i++) {
    vector<int> k;
    long long int gou = 0;
    for(int j = i; j < a; j++) {
      if(gou + c[j] >= b) {
        k.push_back(j);
        for(int v = 0; v < k.size(); v++) {
          d[k[v]] = 1;
        }
        k.resize(0);
      }else {
        k.push_back(j);
        gou += c[j];
      }
    }
  }

  int ans = 0;

  for(int i = 0; i < a; i++) {
    if(!d[i]) ans++;
  }

  cout << ans << endl;
}
