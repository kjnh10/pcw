#include <bits/stdc++.h>

using namespace std;

int n, x, y;
int a[2010];
int dp[2010][2010][2];

int go(int pos, int last, int player) {
	int ret=abs(a[last]-a[n-1]);
	if (pos==n-1) {
		return ret;
	}
	if (dp[pos][last][player]>=0) return dp[pos][last][player];
	if (player==0) {
		for (int i=pos;i<n-1;i++)
			ret=max(ret, go(i+1, i, 1));
	} else {
		for (int i=pos;i<n-1;i++)
			ret=min(ret, go(i+1, i, 0));
	}
	//cout<<pos<<" "<<last<<" "<<player<<" = "<<ret<<endl;
	return dp[pos][last][player]=ret;
}

int main() {
	cin>>n>>x>>y;
	a[0]=x;
	a[1]=y;
	for (int i=0;i<n;i++) cin>>a[i+2];
	memset(dp,-1,sizeof(dp));
	n+=2;
	cout<<go(2, 1, 0)<<endl;
}
