#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << ": " << x << endl;
#define line() cerr << "---------------" << endl;

int main() {
   string s;
   cin >> s;
   cout << count(s.begin(), s.end(), '1') << endl;

   return 0;
}