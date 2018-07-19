#include <string>
#include <iostream>
using namespace std;
string s; bool dp[100009];
int main() {
	cin >> s;
	dp[0] = true;
	for (int i = 5; i <= s.size(); i++) {
		if (dp[i - 5] && s.substr(i - 5, 5) == "dream") dp[i] = true;
		if (i >= 7 && dp[i - 7] && s.substr(i - 7, 7) == "dreamer") dp[i] = true;
		if (dp[i - 5] && s.substr(i - 5, 5) == "erase") dp[i] = true;
		if (i >= 6 && dp[i - 6] && s.substr(i - 6, 6) == "eraser") dp[i] = true;
	}
	cout << (dp[s.size()] ? "YES" : "NO") << endl;
	return 0;
}