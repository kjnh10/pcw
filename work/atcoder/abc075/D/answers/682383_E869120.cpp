#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<map>
using namespace std;
#pragma warning(disable: 4996)
vector<long long>X, Y; long long N, K, x[1000], y[1000], minx = (1LL << 62);
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) { cin >> x[i] >> y[i]; X.push_back(x[i]); Y.push_back(y[i]); }
	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
	for (int i = 0; i < X.size(); i++) {
		for (int j = i + 1; j < X.size(); j++) {
			vector<long long>Z;
			for (int k = 0; k < N; k++) {
				if (X[i] <= x[k] && x[k] <= X[j])Z.push_back(y[k]);
			}
			sort(Z.begin(), Z.end());
			for (int k = 0; k <= (int)Z.size() - K; k++) {
				minx = min(minx, (X[j] - X[i])*(Z[k + K - 1] - Z[k]));
			}
		}
	}
	cout << minx << endl;
	return 0;
}