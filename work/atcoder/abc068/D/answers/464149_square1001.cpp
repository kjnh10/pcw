#include <iostream>
using namespace std;
long long N;
int main() {
	cin >> N;
	cout << 50 << endl;
	for (int i = 0; i < 50; i++) {
		if (i) cout << ' ';
		cout << 49 - i + (N + 49 - i) / 50;
	}
	cout << endl;
	return 0;
}