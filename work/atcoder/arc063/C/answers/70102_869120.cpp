#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
string S;
int main() {
	cin >> S; int cnt = 0;
	for (int i = 1; i < S.size(); i++) {
		if (S[i - 1] != S[i])cnt++;
	}
	cout << cnt << endl;
	return 0;
}