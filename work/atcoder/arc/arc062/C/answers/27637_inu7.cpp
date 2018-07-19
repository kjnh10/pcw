#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long long aa = 0, bb = 0;
  for (int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    if (i == 0) {
      aa = a;
      bb = b;
      continue;
    }
    long long mult = max((aa - 1) / a + 1, (bb - 1) / b + 1);
    aa = a * mult;
    bb = b * mult;
  }
  cout << aa + bb << endl;
}
