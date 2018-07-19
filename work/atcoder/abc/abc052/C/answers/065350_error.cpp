#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define Rep(i, n) for(int i = 1; i <= n; ++i)
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int mod = 1000000007;

int cnt[1009];

int main()
{
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int _i = i;
		for(int j = 2; _i > 1; ++j) {
			while(_i % j == 0) ++cnt[j], _i /= j;
		}
	}
	LL ans = 1;
	Rep(i, n) ans = ans * (cnt[i]+1) % mod;
	cout << ans << endl;
	return 0;
}