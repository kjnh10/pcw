#include <iostream>
using namespace std;

int main() {
	int D, N; cin >> D >> N;

	int S = 1; for (int i = 0; i < D; i++) S *= 100;
	if (N <= 99) {
		cout << S * N << endl;
	}
	else {
		cout << S * 101 << endl;
	}
	return 0;
}