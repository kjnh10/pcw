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
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		string tmp = s;
		int k = a - 1;
		for (int j = b - 1; j >= a - 1; j--) {
			tmp[k] = s[j];
			k++;
		}
		s = tmp;
	}
	cout << s << endl;
	return 0;
}