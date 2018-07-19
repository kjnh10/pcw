#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf (int)1000000007
#define mod (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

signed nex[1141919][26];

int dp[1141919];

string ms;

void solve(int b, int k) {
	if(k == 0) {
		printf("%c\n", ms[b]);
	}
	else {
		if(b > 0) {
			printf("%c", ms[b]);
		}
		k--;
		rep(i, 26) {
			if(nex[b][i] >= 0) {
				if(k < dp[nex[b][i]]) {
					solve(nex[b][i], k);
					break;
				}
				else {
					k -= dp[nex[b][i]];
				}
			}
		}
	}
}

signed main() {
	string s;
	cin >> s;
	ms = "0" + s;
	int dk;
	cin >> dk;
	int sl = ms.size();
	rep(i, sl) {
		rep(j, 26) {
			nex[i][j] = -1;
		}
	}
	mfor(i, 1, sl) {
		rrep(j, i) {
			nex[j][ms[i] - 'a'] = i;
			if(ms[j] == ms[i]) {
				break;
			}
		}
	}
	rrep(i, sl) {
		dp[i] = 1;
		rep(j, 26) {
			if(nex[i][j] >= 0) {
				dp[i] += dp[nex[i][j]];
				if(dp[i] > inf * inf) {
					dp[i] = inf * inf;
				}
			}
		}
	}
	if(dp[0] <= dk) {
		printf("Eel\n");
	}
	else {
		solve(0, dk);
	}
}
