#include <iostream>
#include <cstdio>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main(){
	int n,d[100000],pos[100000],dp[100000][4] = {};
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d",&d[i]);
	sort(d,d + n);
	for(int i = 0;i < n;i++){
		int p = upper_bound(d,d + n,d[i] / 2) - d - 1;
		pos[i] = p;
		dp[i][0] = i + 1;
	}
	for(int i = 1;i < 4;i++){
		for(int j = 0;j < n;j++){
			if(pos[j] != -1){
				dp[j][i] = dp[pos[j]][i - 1];
				if(j != 0) dp[j][i] = (dp[j][i] + dp[j - 1][i]) % MOD;
			}
		}
	}
	cout << dp[n - 1][3] << endl;
	return 0;
}