#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	bool j[2] = { 0,0 };
	cin >> a >> b >> c;

	if (c - b == a)j[0] = true;
	if (c + b == a)j[1] = true;

	if (j[0] && !j[1])cout << '+' << endl;
	else if (!j[0] && j[1])cout << '-' << endl;
	else if (j[0] && j[1])cout << '?' << endl;
	else cout << '!' << endl;

	return 0;
}