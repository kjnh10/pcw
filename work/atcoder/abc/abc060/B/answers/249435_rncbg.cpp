#include "bits/stdc++.h"

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c;

	cin >> a >> b >> c;

	for (int i = 0; i < 1000; i++) {
		if ((a * (i + 1)) % b == c) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}