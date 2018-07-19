#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
int MOD = 1e9 + 7;

double f(double x, double r, double h, double y) {
	double z = max(0.0, min(h, h - (y - x)));
	double _r = r / h * z;
	return _r * _r * acos(-1) * z;
}

int main() {
	int N, Q; cin >> N >> Q;
	vector<int> x(N), r(N), h(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> r[i] >> h[i];
	while (Q--) {
		int A, B; scanf("%d%d", &A, &B);
		double sum = 0;
		for (int i = 0; i < N; i++)
			sum += f(x[i], r[i], h[i], A) - f(x[i], r[i], h[i], B);
		printf("%.15f\n", sum / 3);
	}
}
