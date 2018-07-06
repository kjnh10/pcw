#include <bits/stdc++.h>
using namespace std;

int main() {
	string ss[] = { "Do", "Re", "Mi", "Fa", "So", "La", "Si" };

	string s;
	cin >> s;

	s.resize(12);

	string t = "WBWBWWBWBWBW";
	int a[] = { 0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6 };

	for (int i = 0; i < 12; i++) {
		if (s == t) {
			cout << ss[a[i]] << endl;
			return 0;
		}
		rotate(s.begin(), s.begin() + s.size() - 1, s.end());
	}
}