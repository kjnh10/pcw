#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dp[1000000];
string S;
int main() {
	cin >> S; dp[0] = 1;
	for (int i = 0; i < S.size(); i++) {
		if (dp[i] == 0)continue;
		if (i + 5 <= S.size() && S.substr(i, 5) == "dream")dp[i + 5] = 1;
		if (i + 7 <= S.size() && S.substr(i, 7) == "dreamer")dp[i + 7] = 1;
		if (i + 5 <= S.size() && S.substr(i, 5) == "erase")dp[i + 5] = 1;
		if (i + 6 <= S.size() && S.substr(i, 6) == "eraser")dp[i + 6] = 1;
	}
	if (dp[S.size()] == 1)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}