#include <iostream>
using namespace std;

long long n, p;

int main() {
	cin >> n >> p; p /= 1000;
	for (int i = 0; i <= n; i++) {
		long long rem = p - i * 10, r2 = n - i; if (rem < 0) continue;
		long long minx = r2 * 1, maxx = r2 * 5;
		if (rem < minx || maxx < rem) continue;
		if ((rem - minx) % 4 != 0) continue;
		int p = i, q = (rem - minx) / 4, r = n - p - q;
		cout << p << " " << q << " " << r << endl;
		return 0;
	}
	cout << "-1 -1 -1" << endl;
	return 0;
}