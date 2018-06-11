#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

double m1, m2;
vector<int> d;

int main(){
  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    int dd;
    cin >> dd;
    d.push_back(dd);
  }

  sort(d.begin(), d.end(), greater<int>());

  m1 = d[0];
  m2 = d[0];
  for(int i=1; i<n; i++){
    m1 = m1 - d[i] < 0 ? 0 : m1 - d[i];
    m2 = m2 + d[i];
  }

  cout << m2 << endl << m1 << endl;

  return 0;
}