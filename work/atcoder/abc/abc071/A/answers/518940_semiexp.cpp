#include <cstdio>
#include <cstdlib>

int main()
{
	int x, a, b;
	scanf("%d%d%d", &x, &a, &b);

	int da = abs(x - a), db = abs(x - b);
	if (da < db) {
		puts("A");
	} else {
		puts("B");
	}
	return 0;
}