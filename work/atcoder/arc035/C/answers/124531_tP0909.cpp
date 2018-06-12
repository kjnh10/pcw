#include <iostream>
#include <string>
using namespace std;
int main() {
	int l;
	bool flag = false;
	string s;
	cin >> s;

	l = s.length();
	for (int i = 0; i < l / 2; i++) {
		if (s[i] == s[l - i - 1] || s[i] == '*' || s[l - 1 - i] == '*') {
		}
		else {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}

	return 0;
}