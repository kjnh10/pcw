#include <bits/stdc++.h>
using namespace std;
int main() {
	long long X;
	cin >> X;
	long long y = X / 11 * 2;
	if (X % 11 == 0) ;
	else if (X % 11 <= 6) y += 1;
	else y += 2;
	cout << y << endl;
}
