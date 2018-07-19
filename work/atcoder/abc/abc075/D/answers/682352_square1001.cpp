#include <iostream>
#include <algorithm>
using namespace std;
int N, K, x[55], y[55];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	long long ret = 1LL << 62;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (x[i] <= x[j] && y[k] <= y[l]) {
						int cnt = 0;
						for (int p = 0; p < N; p++) {
							if (x[i] <= x[p] && x[p] <= x[j] && y[k] <= y[p] && y[p] <= y[l]) cnt++;
						}
						if (cnt >= K) ret = min(ret, 1LL * (x[j] - x[i]) * (y[l] - y[k]));
					}
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}