#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int N; int K;
	while(~scanf("%d%d", &N, &K)) {
		vector<vector<double>> dp(N + 1, vector<double>(K + 1));
		double q = 1;
		for(int i = N - 1; i >= 0; -- i) {
			rer(j, 0, K) {
				double prob = 1. / (i + 1);
				double x = 0;
				amax(x, dp[i + 1][j]);
				if(j > 0)
					amax(x, q +  dp[i + 1][j - 1]);
				dp[i][j] = prob * x + (1 - prob) * dp[i + 1][j];
			}
			q *= i * 1. / (i + 1);
		}
		double ans = dp[0][K];
		printf("%.10f\n", ans);
	}
	return 0;
}
