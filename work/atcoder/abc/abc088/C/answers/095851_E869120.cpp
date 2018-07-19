#include <iostream>
using namespace std;

int a[3][3];

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cin >> a[i][j];
		a[i][1] -= a[i][0]; a[i][2] -= a[i][0]; a[i][0] = 0;
	}
	for (int i = 0; i < 3; i++) {
		if (!(a[0][i] == a[1][i] && a[1][i] == a[2][i])) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}