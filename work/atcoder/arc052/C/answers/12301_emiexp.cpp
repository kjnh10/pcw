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
#include <cmath>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

char S[55];

int main()
{
	scanf("%s", S);
	int ans = 0;
	for (int i = 0; S[i]; ++i) {
		if (S[i] >= '0' && S[i] <= '9') ans = ans * 10 + (S[i] - '0');
	}
	printf("%d\n", ans);
	return 0;
}
