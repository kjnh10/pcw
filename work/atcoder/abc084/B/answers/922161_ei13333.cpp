#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main()
{
  int A, B;
  string S;
  cin >> A >> B;
  cin >> S;
  for(int i = 0; i < S.size(); i++) {
    if(i != A) {
      if(!isdigit(S[i])) {
        cout << "No" << endl;
        return (0);
      }
    } else {
      if(S[i] != '-') {
        cout << "No" << endl;
        return (0);
      }
    }
  }
  cout << "Yes" << endl;
}