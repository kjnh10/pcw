#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int b[500][500], a[500][500];
int dx[]{ 1,-1,0,0 }, dy[]{ 0,0,1,-1 };
int main() {
	int n, m; scanf("%d%d", &n, &m);
	rep(i, n)rep(j, m)scanf("%1d", &b[i][j]);
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int Min = INT_MAX;
			rep(k, 4)Min = min(Min, b[i + dx[k]][j + dy[k]]);
			a[i][j] = Min;
			rep(k, 4)b[i + dx[k]][j + dy[k]] -= Min;
		}
	}
	rep(i, n) {
		rep(j, m)printf("%d", a[i][j]);
		printf("\n");
	}
}