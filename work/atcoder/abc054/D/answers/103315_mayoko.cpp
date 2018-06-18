#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int dp[44][444][444];
int A[44], B[44], C[44];
const int INF = 1e9;

int main() {
	int N, Ma, Mb;
	cin >> N >> Ma >> Mb;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}
	for (int i = 0; i < 44; i++)
		for (int j = 0; j < 444; j++)
			for (int k = 0; k < 444; k++)
				dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int a = 0; a < 444; a++) {
			for (int b = 0; b < 444; b++) {
				dp[i+1][a+A[i]][b+B[i]] = min(dp[i+1][a+A[i]][b+B[i]], dp[i][a][b] + C[i]);
				dp[i+1][a][b] = min(dp[i+1][a][b], dp[i][a][b]);
			}
		}
	}
	int ans = INF;
	for (int i = 1; i < 444; i++) {
		for (int j = 1; j < 444; j++) {
			int g = __gcd(i, j);
			if (i/g == Ma && j/g == Mb) ans = min(ans, dp[N][i][j]);
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}
