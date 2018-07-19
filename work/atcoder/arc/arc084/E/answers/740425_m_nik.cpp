#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 300300;
int n, k;
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &k, &n);
	
	if (k % 2 == 0) {
		printf("%d", k / 2);
		for (int i = 1; i < n; i++)
			printf(" %d", k);
		printf("\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
		a[i] = (k + 1) / 2;
	int s = n / 2;
	int L = n;
	while(s--) {
		if (a[L - 1] == 1) {
			L--;
			continue;
		}
		a[L - 1]--;
		while(L < n)
			a[L++] = k;
	}
	for (int i = 0; i < L; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
