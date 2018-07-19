#include <iostream>
using namespace std;

int A, N;

int main() {
	cin >> N >> A;
	if (N % 500 <= A) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}