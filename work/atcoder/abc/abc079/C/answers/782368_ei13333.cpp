#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  string s;
  cin >> s;
  for(int i = 0; i < (1 << 3); i++) {
    int cur = s[0] - '0';
    string v;
    v += s[0];
    for(int j = 1; j < 4; j++) {
      if((i >> (j - 1)) & 1) {
        cur += s[j] - '0';
        v += "+";
        v += s[j];
      } else {
        cur -= s[j] - '0';
        v += "-";
        v += s[j];
      }
    }
    if(cur == 7) {
      cout << v << "=7" << endl;
      return(0);
    }
  }

}
