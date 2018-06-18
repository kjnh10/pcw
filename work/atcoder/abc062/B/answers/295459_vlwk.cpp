#include <bits/stdc++.h>
using namespace std;

char str[105][105];
char tmp[105];

int main() {
	/* freopen("input.in", "r", stdin);
	freopen("output.o", "w", stdout); */
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) str[i][j] = '#';
	}
	for (int i = 1; i <= h; i++) {
		scanf("%s", tmp);
		int n = strlen(tmp);
		for (int j = 0; j < n; j++) str[i][j+1] = tmp[j];
	}
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) printf("%c", str[i][j]);
		printf("\n");
	}
}