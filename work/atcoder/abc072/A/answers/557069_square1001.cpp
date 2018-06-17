#include <iostream>
#include <algorithm>
using namespace std;
int X, t;
int main() {
	cin >> X >> t;
	cout << max(X - t, 0) << endl;
}