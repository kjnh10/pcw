#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string t;
	for (char c : s) if (isdigit(c)) t += c;
	cout << stoll(t) << endl;
}