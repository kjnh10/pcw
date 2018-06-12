#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	int ret = 1;
	for (int i = 1; i < 10; i++) {
		if ((1 << i) <= n) ret = 1 << i;
	}
	cout << ret << endl;
	return 0;
}