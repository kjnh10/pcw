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
signed main() {
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] > 'Z'&&i==0) cout << (char)('A' + s[i] - 'a');
		else if (s[i] <= 'Z'&&i != 0) cout << (char)('a' + s[i] - 'A');
		else cout << s[i];
	}
	cout << endl;
	return 0;
}