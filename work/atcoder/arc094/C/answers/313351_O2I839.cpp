#include <bits/stdc++.h>
using namespace std;

int A[3];

int main() {
	for (int i = 0; i < 3; ++i) scanf("%d", A+i);
	sort(A, A+3);
	
	int tot = 0;
	while (A[1] < A[2]) A[0]++, A[1]++, tot++;
	while (A[0] < A[1]) A[0] += 2, tot++;
	if (A[0] > A[1]) tot++;

	printf("%d\n", tot);
}