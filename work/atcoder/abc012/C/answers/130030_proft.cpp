#include<iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	int d = 2025 - n;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i*j == d) {
				cout << i << ' ' << 'x' << ' ' << j << endl;
			}
		}
	}

	return 0;
}