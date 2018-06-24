#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int AMAX = 100000;
ll cnt[AMAX + 1];

int main(void) {
	int N;
	ll K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		int A, B;
		cin >> A >> B;
		cnt[A] += B;
	}

	for (int ans = 1; ans <= AMAX; ++ans){
		if (K <= cnt[ans]) {
			cout << ans << endl;
			break;
		}
		K -= cnt[ans];
	}

	return 0;
}