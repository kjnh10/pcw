#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
int a[26]; bool OK = false; string S;
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		a[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)if (a[i] % 2 == 1)OK = true;
	if (OK == false)cout << "Yes" << endl;
	else { cout << "No" << endl; }
	return 0;
}