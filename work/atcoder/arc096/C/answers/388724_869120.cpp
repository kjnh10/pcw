#include <iostream>
#include <algorithm>
using namespace std;

long long A, B, C, X, Y, minx = (1LL << 60);

int main() {
	cin >> A >> B >> C >> X >> Y;
	for (long long i = 0; i <= 100000; i++) {
		long long x = max(0LL, X - i);
		long long y = max(0LL, Y - i);
		minx = min(minx, x*A + y*B + i*C * 2);
	}
	cout << minx << endl;
	return 0;
}