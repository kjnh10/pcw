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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

char S[505050]; int N;
int fail[505050], fail2[505050];

int kmp(int *feil)
{
	int m = strlen(S), i, j = feil[0] = -1;
	for (i = 0; i < m; ++i) {
		for (; ~j && S[j] != S[i]; j = feil[j]);
		feil[i + 1] = ++j;
	}
	return m;
}

bool isok(int i, int f)
{
	return i % (i - f) != 0 || f == 0;
}

int main()
{
	scanf("%s", S);
	N = strlen(S);

	kmp(fail);

	if (isok(N, fail[N])) {
		printf("1\n1\n");
		return 0;
	}
	if (N - fail[N] == 1) {
		printf("%d\n1\n", N);
		return 0;
	}
	reverse(S, S + N);
	kmp(fail2);

	int ret = 0;
	for (int i = 1; i < N; ++i) {
		if (isok(i, fail[i]) && isok(N - i, fail2[N - i])) {
			++ret;
		}
	}
	printf("%d\n%d\n", 2, ret);
	return 0;
}
