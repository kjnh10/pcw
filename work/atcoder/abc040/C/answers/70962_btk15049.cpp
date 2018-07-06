/*
* Problem link
* 
*/

#include<bits/stdc++.h>
using namespace std;

struct INIT{INIT(){cin.tie(0);ios_base::sync_with_stdio(false);} }init;
#define rep(i,n) for(auto i=(n)*0;i<n;i++)
#define range(i,v) for(auto &i:v)
typedef long long LL;
const LL INF = (LL)1e15;
int main() {
#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	int N;
	cin >> N;
	vector<LL> a(N);
	range(it, a)cin >> it;
	vector<LL> dp(N,INF);
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);
	rep(i, N - 2) {
		dp[i + 2] = min(dp[i] + abs(a[i + 2] - a[i]), dp[i + 1] + abs(a[i + 2] - a[i + 1]));
	}
	cout << dp.back() << endl;

	return 0;
}
