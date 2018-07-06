#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
#include <cmath>
#include <cctype>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i == 0)s[i] = toupper(s[i]);
		else s[i] = tolower(s[i]);
	}

	cout << s << endl;
	return 0;
}