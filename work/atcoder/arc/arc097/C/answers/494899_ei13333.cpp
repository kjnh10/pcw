#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string s;
  cin >> s;
  set< string > st;
  for(int i = 0; i < s.size(); i++) {
    for(int j = 1; j <= 10; j++) {
      st.emplace(s.substr(i, j));
    }
  }
  auto cur = st.begin();
  int K;
  cin >> K;
  --K;
  while(K--) ++cur;
  cout << *cur << endl;
}
