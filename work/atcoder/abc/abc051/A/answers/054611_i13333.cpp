#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  for(char &c : S) {
    if(c == ',') cout << " ";
    else cout << c;
  }
  cout << endl;

}