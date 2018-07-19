#include <iostream>

using namespace std;

int main() {

	int n,a;
	cin >> n;
	
	a = (n*(n + 1)) / 2;
	cout << a * 10000 / n << endl;


	return 0;
}