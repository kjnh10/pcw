#include<stdio.h>
#include<string.h>

/*
奇数なら、
(n-1)... 4 2 0 2 4 ...
偶数なら、
(n-1)... 3 1 1 3 ...
となる。2^(n/2)が答え。
*/

long long sum(long long a, long long b) {
	return (a + b) % 1000000007;
}

int main(void) {
	int N;
	int i,p,h;
	int A[100000];
	long long ans;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		A[i] = 0;
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &p);
		A[p]++;
	}

	h = 2;
	for (i = N - 1; i >= 1; i--) {
		if (A[i] != h) { printf("0\n"); return 0; }
		h = 2 - h;
	}

	ans = 1;
	for (i = 0; i < N / 2; i++) {
		ans = sum(ans, ans);
	}

	printf("%lld\n", ans);



	return 0;
}