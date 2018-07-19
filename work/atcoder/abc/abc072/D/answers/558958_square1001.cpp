#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
	string s = "0";
	for (int i = 0; i < n; i++) {
		if (p[i] == i) s += "1";
		else s += "0";
	}
	s += "0";
	int l = -1, ret = 0;
	for (int i = 0; i <= n; i++) {
		if (s[i] == '0' && s[i + 1] == '1') {
			l = i;
		}
		if (s[i] == '1' && s[i + 1] == '0') ret += (i - l + 1) / 2;
	}
	cout << ret << endl;
	return 0;
}