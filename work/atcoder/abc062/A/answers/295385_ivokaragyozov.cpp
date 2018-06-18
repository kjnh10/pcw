#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	int nums[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2 ,1};
	printf("%s\n", (nums[x] == nums[y] ? "Yes" : "No"));

	return 0;
}