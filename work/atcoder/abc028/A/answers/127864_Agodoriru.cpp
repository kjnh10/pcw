#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 100) {
		cout << "Perfect" << endl;
	}
	else if (90 <= n&&n<100) {
		cout << "Great" << endl;
	}
	else if (60 <= n&&n<90) {
		cout << "Good" << endl;
	}
	else if (n<60) {
		cout << "Bad" << endl;
	}

	return 0;

}