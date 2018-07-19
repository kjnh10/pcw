#include <iostream>
#include <algorithm>

using namespace std;

int c[4];

int main(){
  int n;
  cin >> n;

  string in;
  cin >> in;

  for(int i=0; i<n; i++){
    c[in[i] - '1']++;
  }

  sort(c,c+4);

  cout << c[3] << " " << c[0] << endl;

  return 0;
}