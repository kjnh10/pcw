#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int D, N;

int ord(int a, int b)
{
	int ret = 0;
	while (a % b == 0) {
		++ret;
		a /= b;
	}
	return ret;
}

int main()
{
	scanf("%d%d", &D, &N);

	for (int i = 1;; ++i) {
		if (ord(i, 100) == D) {
			if (--N == 0) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	return 0;
}
