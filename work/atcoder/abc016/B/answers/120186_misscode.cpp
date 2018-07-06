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
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c&&a - b == c) cout << "?" << endl;
	else if (a + b == c) cout << "+" << endl;
	else if (a - b == c) cout << "-" << endl;
	else cout << "!" << endl;
	return 0;
}