#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x;
	cin >> x;
	for (long long i = 1;; i++) {
		if (i * i * i * i == x) {
			cout << i << endl;
			return 0;
		}
	}
}