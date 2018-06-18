#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>dp(100001, MOD);
	set<int>s;
	s.insert(1);
	for (int i = 6; i < 100000; i *= 6) {
		s.insert(i);
	}
	for (int i = 9; i < 100000; i *= 9) {
		s.insert(i);
	}
	dp[0] = 0;
	for (int i = 0; i < 100000; i++) {
		for (auto j : s) {
			if (i + j <= 100000) {
				dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
	}
	cout << dp[N] << endl;
	return 0;
}