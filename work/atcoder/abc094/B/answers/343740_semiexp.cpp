#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, X, A[200];

int main()
{
	scanf("%d%d%d", &N, &M, &X);
	for (int i = 0; i < M; ++i) scanf("%d", A + i);

	int left = 0, right = 0;
	for (int i = 0; i < M; ++i) {
		if (A[i] < X) ++left;
		else ++right;
	}
	printf("%d\n", min(left, right));

	return 0;
}
