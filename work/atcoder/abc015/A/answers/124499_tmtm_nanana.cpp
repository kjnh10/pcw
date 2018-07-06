#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	if (a.size() > b.size()) {
		cout << a << endl;
	}
	else {
		cout << b << endl;
	}
	return 0;
}