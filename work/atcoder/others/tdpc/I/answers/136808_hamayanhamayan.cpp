#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)




string S;
//-----------------------------------------------------------------
bool dp1[300][300];
int dp2[300];
int main() {
	cin >> S;
	int N = S.length();

	rep(L, 0, N - 2) {
		int R = L + 2;
		if (S.substr(L, 3).compare("iwi") == 0) dp1[L][R] = true;
	}

	for (int len = 6; len <= N; len += 3) rep(L, 0, N){
		int R = L + len - 1;
		if (N <= R) break;

		// ok + ok
		for (int C = L + 3; C < R; C += 3) {
			if (dp1[L][C - 1] && dp1[C][R]) dp1[L][R] = true;
		}
		// 'i' + ok + 'w' + ok + 'i'
		rep(C, L + 1, R) if (S[L] == 'i' && S[C] == 'w' && S[R] == 'i') {
			if (L + 1 != C && !dp1[L + 1][C - 1]) continue;
			if (C + 1 != R && !dp1[C + 1][R - 1]) continue;
			dp1[L][R] = true;
		}
	}

	rep(R, 1, N) {
		dp2[R] = dp2[R - 1];
		rep(L, 0, R) {
			if (dp1[L][R]) {
				if (L == 0)
					dp2[R] = max(dp2[R], (R - L + 1) / 3);
				else
					dp2[R] = max(dp2[R], dp2[L - 1] + (R - L + 1) / 3);
			}
		}
	}

	cout << dp2[N - 1] << endl;
}