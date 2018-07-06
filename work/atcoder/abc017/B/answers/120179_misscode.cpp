#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <float.h>
#include <cmath>
#include <cstring>

using namespace std;
#define int long long

bool tmp[1000000] = {};
signed main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'c'&&i!=s.length()-1) {
			if (s[i + 1] == 'h') i++;
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
		else if (s[i] == 'o') continue;
		else if (s[i] == 'k') continue;
		else if (s[i] == 'u') continue;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}