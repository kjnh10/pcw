#include <bits/stdc++.h>
using namespace std;

int grp(int x) {
	if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) return 1;
	if (x == 4 || x == 6 || x == 9 || x == 11) return 2;
	return 3;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (grp(x) == grp(y)) puts("Yes");
	else puts("No");
}