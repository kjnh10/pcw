#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
#include<numeric>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  int ave = accumulate(a.begin(), a.end(), 0);
  if(ave % n) {
    cout << -1 << endl;
    return 0;
  }

  ave /= n;
  int sum = 0, ans = 0;
  for(int i=0; i<n; i++) {
    if(sum != i*ave) ans++;
    sum += a[i];
  }
  cout << ans << endl;
}