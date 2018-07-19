#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.in", "r", stdin);
	// freopen("output.o", "w", stdout);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x = a + b;
	int y = b + c;
	int z = a + c;
	int ans = min(min(x, y), z);
	printf("%d", ans);
}