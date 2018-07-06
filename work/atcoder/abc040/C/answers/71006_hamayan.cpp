#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF INT_MAX/2

int N;
int A[101010];
int dp[101010];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N)
	{
		rep(i, 0, N) cin >> A[i];

		rep(i, 0, N + 1) dp[i] = INF;
		dp[0] = 0;

		rep(i, 0, N)
		{
			dp[i + 1] = min(dp[i + 1], dp[i] + abs(A[i] - A[i + 1]));
			dp[i + 2] = min(dp[i + 2], dp[i] + abs(A[i] - A[i + 2]));
		}

		//rep(i, 0, N) cout << dp[i] << endl;
		cout << dp[N - 1] << endl;
	}
}