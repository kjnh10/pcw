#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int N, b, v[109], p[109][109];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> b;
			v[i] |= b << j;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 10; j++) {
			cin >> p[i][j];
		}
	}
	int ret = -1012345678;
	for (int i = 1; i < 1 << 10; i++) {
		int res = 0;
		for (int j = 0; j < N; j++) {
			int bc = 0;
			for (int k = 0; k < 10; k++) {
				if ((v[j] & i) & (1 << k)) bc++;
			}
			res += p[j][bc];
		}
		ret = max(ret, res);
	}
	cout << ret << endl;
	return 0;
}