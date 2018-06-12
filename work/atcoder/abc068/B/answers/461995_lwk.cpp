#include <bits/stdc++.h>
using namespace std;

int main() {
	/* freopen("input.in", "r", stdin);
	freopen("output.o", "w", stdout); */
	int n;
	scanf("%d", &n);
	int x = log2(n);
	printf("%d", (1 << x));
}