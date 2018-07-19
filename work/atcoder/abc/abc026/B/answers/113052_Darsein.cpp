#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> r(n);
  for(int i=0; i<n; i++) cin >> r[i];
  sort(r.begin(), r.end(), greater<int>());

  double ans = 0;
  for(int i=0; i<n; i++) {
    if(i%2==0) ans += r[i] * r[i];
    else ans -= r[i] * r[i];
  }
  cout << fixed << setprecision(10) << ans * acos(-1) << endl;
}