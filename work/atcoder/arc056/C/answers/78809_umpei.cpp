#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, k, l;
	cin >> a >> b >> k >> l;

	long long x1 = (k % l) * a + k / l * b;
	long long x2 = (k + l - 1) / l * b;

	cout << min(x1, x2) << endl;
}