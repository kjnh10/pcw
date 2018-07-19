//Kaori Miyazono, did I reach you ?
//"I can't die because... I have to protect you." -Asuna Yuuki

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	if (s < t) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}	




