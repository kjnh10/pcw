#include<iostream>
using namespace std;
int main() {
	string a, b;
	int hikaku[2];
	cin >> a >> b;
	hikaku[0] = a.length();
	hikaku[1] = b.length();
	if (hikaku[0] > hikaku[1])cout << a;
	else cout << b;
	return 0;

}