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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>a(N);
	vector<long long int>b(N);
	long long int max_a = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		max_a = max(max_a, a[i]);
	}
	priority_queue<long long int>PQ;
	for (int i = 0; i < N; i++) {
		if (b[i] > max_a) {
			PQ.push(b[i]);
		}
	}
	while (K > 0 && !PQ.empty()) {
		K -= PQ.top();
		PQ.pop();
		M++;
	}
	if (K > 0) {
		M += K / max_a + !!(K%max_a);
	}
	cout << M << endl;
	return 0;
}