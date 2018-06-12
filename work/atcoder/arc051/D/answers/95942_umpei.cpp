#include <bits/stdc++.h>
using namespace std;

long long F[43];

int main() {
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < 43; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}

	int K;
	cin >> K;
	cout << F[K + 2] << " " << F[K + 1] << endl;
}