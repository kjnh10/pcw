#include <bits/stdc++.h>

using namespace std;

string s1 = "ABXY";

int countCommand(string s, string L, string R) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		string tmp = s.substr(i, 2);
		if (tmp == L || tmp == R) i++;
		res++;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> command;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			command.push_back(string(1, s1[i]) + s1[j]);
		}
	}
	int ans = n;
	for (int i = 1; i < command.size(); i++) {
		for (int j = 0; j < i; j++) {
			ans = min(ans, countCommand(s, command[i], command[j]));
		}
	}
	cout << ans << endl;
	return 0;
}