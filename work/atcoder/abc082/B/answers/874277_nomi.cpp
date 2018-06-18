#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define debug(x) cerr << #x << ": " << x << endl;
#define line() cerr << "---------------" << endl;

int main() {
   string a, b;
   cin >> a >> b;
   sort(a.begin(), a.end());
   sort(b.begin(), b.end(), greater<char>());
   if (a < b) {
      puts("Yes");
   } else {
      puts("No");
   }

   return 0;
}