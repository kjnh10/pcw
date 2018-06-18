#include<bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  string T = S;
  reverse(begin(T), end(T));
  if(S == T) cout << "Yes" << endl;
  else cout << "No" << endl;
}
