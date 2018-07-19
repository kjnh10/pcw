#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	string t;
	for (int i = 0; i < s.size(); i += 2) {
		t += s[i];
	}
	cout << t << endl;
	return 0;
}