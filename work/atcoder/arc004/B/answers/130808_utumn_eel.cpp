#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int d[500];
int main() {
	int n; scanf("%d", &n);
	int Max = 0, sum = 0;
	rep(i, n)scanf("%d", &d[i]), Max = max(Max, d[i]), sum += d[i];
	printf("%d\n", sum);
	sum -= Max;
	printf("%d\n", max(0, Max - sum));
}