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

const int MAXN = 100100;
const int MOD = 1e9+7;
int cnt[MAXN];

int solve(int N) {
	ll ans = 1;
	if (N % 2 == 1) {
		if (cnt[0] != 1) return 0;
		for (int i = 2; i < N; i += 2) {
			if (cnt[i] != 2) return 0;
			(ans *= 2) %= MOD;
		}
		return ans;
	} else {
		for (int i = 1; i < N; i+=2) {
			if (cnt[i] != 2) return 0;
			(ans *= 2) %= MOD;
		}
		return ans;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	cout << solve(N) << endl;
	return 0;
}
