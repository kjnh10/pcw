#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	if (b == 0 && a == c) {
		cout << "?" << endl;
	} else if (a + b == c) {
		cout << "+" << endl;
	} else if (a - b == c) {
		cout << "-" << endl;
	} else {
		cout << "!" << endl;
	}
	return (0);
}