#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
using namespace std;

int n, k, x[100009], y[100009], I[4009][4009], J[4009][4009], maxn; char c[100009];

int areas(int p, int q, int r, int s, int ty) {
	if (ty == 1) {
		return I[p][q] + I[r][s] - I[p][s] - I[r][q];
	}
	if (ty == 2) {
		return J[p][q] + J[r][s] - J[p][s] - J[r][q];
	}
	return 0;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> c[i];
		x[i] %= (2 * k); y[i] %= (2 * k);
		if (c[i] == 'W') {
			I[x[i]][y[i]]++; I[x[i] + 2 * k][y[i]]++;
			I[x[i]][y[i] + 2 * k]++; I[x[i] + 2 * k][y[i] + 2 * k]++;
		}
		if (c[i] == 'B') {
			J[x[i]][y[i]]++; J[x[i] + 2 * k][y[i]]++;
			J[x[i]][y[i] + 2 * k]++; J[x[i] + 2 * k][y[i] + 2 * k]++;
		}
	}
	for (int i = 0; i < 4009; i++) {
		for (int j = 1; j < 4009; j++) {
			I[i][j] += I[i][j - 1];
			J[i][j] += J[i][j - 1];
		}
	}
	for (int i = 1; i < 4009; i++) {
		for (int j = 0; j < 4009; j++) {
			I[i][j] += I[i - 1][j];
			J[i][j] += J[i - 1][j];
		}
	}
	for (int i = 0; i < 2 * k; i++) {
		for (int j = 0; j < 2 * k; j++) {
			int P1 = areas(i + k * 0, j + k * 0, i + k * 1, j + k * 1, 1);
			int P2 = areas(i + k * 1, j + k * 0, i + k * 2, j + k * 1, 2);
			int P3 = areas(i + k * 0, j + k * 1, i + k * 1, j + k * 2, 2);
			int P4 = areas(i + k * 1, j + k * 1, i + k * 2, j + k * 2, 1);
			maxn = max(maxn, P1 + P2 + P3 + P4);
		}
	}
	cout << maxn << endl;
	return 0;
}