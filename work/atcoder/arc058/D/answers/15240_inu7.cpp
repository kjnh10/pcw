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

const int mmod = 1000000007;
	int inv_mod(int a, int b) {
		if (a == 1) return b;
		int div = mmod / a + 1;
		return inv_mod((a * (long long)div) % mmod, (b * (long long)div) % mmod);
	}

int fac[999999];

int calc(int a, int b) {
  int ret = fac[a+b] ;
  ret = (ret * 1LL * inv_mod(fac[a], 1)) % mmod;
  ret = (ret * 1LL * inv_mod(fac[b], 1)) % mmod;
  return ret;
}

int main()
{
  fac[0] = 1;
  for (int i=1; i<222222; i++)
    fac[i] = (fac[i-1] * 1LL * i) % mmod;

  int h, w, a, b;
  cin >> h >> w >> a >> b;

  int res = 0;
  for (int i=1; i<=h-a; i++)
    res = (res + 1LL * calc(b-1, i-1) * calc(w-b-1, h-i)) % mmod;
  printf("%d\n", res);
}
