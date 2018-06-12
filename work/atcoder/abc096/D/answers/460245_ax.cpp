//Daniel Grzegorzewski
#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ST first
#define ND second

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

bool prime(int x)
{
  if (x < 2)
    return false;
  for (int i = 2; i*i <= x; ++i)
    if (x%i == 0)
      return false;
  return true;
}

int n;
VI v;

int main() {
  init_ios();
  cin >> n;
  for (int i = 2; v.size() < n; ++i)
    if (prime(i) && (i%5) == 1)
      v.PB(i);
  for (int x: v)
    cout<<x<<" ";
  cout<<"\n";
}