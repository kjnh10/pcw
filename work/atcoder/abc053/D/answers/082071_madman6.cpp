#include <iostream>
#define MAX 100001
using namespace std;

int a[MAX];
int count[MAX];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < MAX; i++)
    count[i] = 0;

  for (int i = 0; i < n; i++)
    count[a[i]]++;

  int sum = 0;
  for (int i = 0; i < MAX; i++) {
    if (count[i] == 0) continue;
    sum += count[i] - 1;
  }
  if (sum % 2) cout << n - sum - 1 << endl;
  else cout << n - sum << endl;

  return 0;
}
