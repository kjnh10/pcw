#include <bits/stdc++.h>
using namespace std;

int n, a[1025], s[2048], e[2048];
double dp[2048][1025];

int main(){
	scanf("%d", &n); n = 1 << n;
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = n; i < 2 * n; i++){
		s[i] = e[i] = i - n + 1;
		dp[i][i - n + 1] = 1;
	}
	for(int i = n - 1; i >= 1; i--){
		s[i] = s[2 * i]; e[i] = e[2 * i + 1];
		double t, u;
		for(int j = s[2 * i]; j <= e[2 * i]; j++){
			for(int k = s[2 * i + 1]; k <= e[2 * i + 1]; k++){
				t = dp[2 * i][j] * dp[2 * i + 1][k];
				u = 1.0 / (1 + pow(10, (a[k] - a[j]) / 400.0));
				dp[i][j] += t * u;
				dp[i][k] += t * (1 - u);
			}
		}
	}
	for(int i = 1; i <= n; i++) printf("%.9f\n", dp[1][i]);
}
