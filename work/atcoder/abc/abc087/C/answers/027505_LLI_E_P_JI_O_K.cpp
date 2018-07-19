#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;
 
int const MAX_N = 128 * 1024;
 
int s[2][MAX_N], dp[2][MAX_N];

int main() {
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
	int n;
	cin>>n;
	for (int i=0; i<2; i++)
		for (int j=0; j<n; j++) {
			cin>>s[i][j];
			dp[i][j] = -1;
			dp[i][j+1] = -1;
		}
	dp[0][0] = s[0][0];
	for (int j=0; j<n; j++) {
		dp[1][j] = max(dp[1][j], dp[0][j] + s[1][j]);
		if (j+1<n)
			for (int i=0; i<2; i++)
				dp[i][j+1] = max(dp[i][j+1], dp[i][j] + s[i][j+1]);
	}

	cout<<dp[1][n-1];
    return 0;
}  
