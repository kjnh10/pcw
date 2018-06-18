
#include <stdio.h>
#include <stdlib.h>

#define abs(a) ((a) < 0 ? - (a) : (a))

int main() {

	int N, Z, W;
	int a[2345];

	scanf("%d %d %d", &N, &Z, &W);

	for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	if (N == 1) printf("%d\n", abs(a[0] - W));
	else if (abs(a[N - 2] - a[N - 1]) > abs(a[N - 1] - W)) printf("%d\n", abs(a[N - 2] - a[N - 1]));
	else printf("%d\n", abs(a[N - 1] - W));

	return 0;
}