#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, H, a[100009], b[100009], maxn, ret = (1LL << 60); vector<long long>P;

long long solve(long long p, long long q) {
	if (p < 0)return 0;
	return (p + q - 1) / q;
}

int main() {
	cin >> N >> H;
	for (int i = 1; i <= N; i++) {
		cin >> a[i] >> b[i]; P.push_back(b[i]);
		maxn = max(maxn, a[i]);
	}
	sort(P.begin(), P.end()); reverse(P.begin(), P.end());
	long long L = 0;
	for (int i = 0; i <= N; i++) {
		ret = min(ret, i + solve(H - L, maxn));
		if (i != N) L += P[i];
	}
	cout << ret << endl;
	return 0;
}