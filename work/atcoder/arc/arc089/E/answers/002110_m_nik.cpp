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

const int M = 101;
int A, B;
int d[M][M];
int a[M][M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &A, &B);
	for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++)
			scanf("%d", &d[i][j]);
	for (int x = 0; x < M; x++)
		for (int y = 0; y < M; y++) {
			a[x][y] = 0;
			for (int i = 1; i <= A; i++)
				for (int j = 1; j <= B; j++) {
					a[x][y] = max(a[x][y], d[i][j] - i * x - j * y);
				}
		}
	for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++) {
			bool ok = false;
			for (int x = 0; x < M; x++)
				for (int y = 0; y < M; y++) {
					if (a[x][y] + i * x + j * y == d[i][j])
						ok = true;
				}
			if (!ok) {
				printf("Impossible\n");
				return 0;
			}
		}
	printf("Possible\n");
	printf("%d %d\n", 2 * M, 2 * M - 2 + M * M);
	for (int i = 0; i < M - 1; i++) {
		printf("%d %d X\n", 1 + i, 1 + i + 1);
		printf("%d %d Y\n", 1 + M + i + 1, 1 + M + i);
	}
	for (int x = 0; x < M; x++)
		for (int y = 0; y < M; y++)
			printf("%d %d %d\n", 1 + x, 1 + M + y, a[x][y]);
	printf("1 %d\n", M + 1);

	return 0;
}
