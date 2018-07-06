#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int N, M, P, Q, R;
	cin >> N >> M >> P >> Q >> R;
	vector<int> x(R), y(R), z(R);
	for (int i = 0; i < R; i++) {
		cin >> x[i] >> y[i] >> z[i];
		x[i]--;
		y[i]--;
	}
	int res = 0;
	for (int i = 1; i < (1 << N); i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				cnt++;
			}
		}
		if (cnt == P) {
			vector<int> val(M);
			for (int j = 0; j < R; j++) {
				if (i & (1 << x[j])) {
					val[y[j]] += z[j];
				}
			}
			sort(val.begin(), val.end());
			int sum = 0;
			for (int j = 0; j < Q; j++) {
				sum += val[M - 1 - j];
			}
			res = max(res, sum);
		}
	}
	cout << res << endl;
	return 0;
}
