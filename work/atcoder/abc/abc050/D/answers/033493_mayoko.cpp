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

const int MOD = 1e9+7;
ll dp[62][3];
ll N;

ll dfs(int keta, int diff) {
	if (keta == -1) return 1;
	ll& ret = dp[keta][diff];
	if (ret >= 0) return ret;
	if ((1ll<<keta) > N) return ret = dfs(keta-1, diff);
	ret = 0;
	int digit = (N>>keta)&1;
	// 両方 0
	ret += dfs(keta-1, min(2*diff+digit, 2));
	// 片方 1
	if (2*diff+digit >= 1) ret += dfs(keta-1, min(2*diff+digit-1, 2));
	// 片方 1
	if (2*diff+digit >= 2) ret += dfs(keta-1, min(2*diff+digit-2, 2));
	ret %= MOD;
	return ret;
}

int main() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << dfs(60, 0) << endl;
	return 0;
}
