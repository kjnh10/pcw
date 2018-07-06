#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

int main(void) {
	int n, i=0, j, count = 0;
	string s;
	string ans;
	cin >> n >> s;
	ans = 'b';
	if (s[s.size() / 2] != 'b'||s.size()%2==0) {
		cout << -1 << endl;
		return 0;
	}
	if (ans == s) {
		cout << i << endl;
		return 0;
	}

	for (i = 1; i < n; i++) {
		if (i % 3 == 0) {
			ans += 'b';
			ans = 'b' + ans;
		}
		else if (i % 3 == 1) {
			ans = 'a' + ans + 'c';
		}
		else {
			ans = 'c' + ans + 'a';
		}
		if (ans == s) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}