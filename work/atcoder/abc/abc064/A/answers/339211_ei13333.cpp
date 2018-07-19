#include<bits/stdc++.h>

using namespace std;

int main()
{
  int R, G, B;
  cin >> R >> G >> B;
  if((R * 100 + G * 10 + B) % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}