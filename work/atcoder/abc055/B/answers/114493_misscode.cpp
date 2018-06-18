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
	int N;
	cin >> N;
	int tmp = 1;
	for (int i = 1; i <= N; i++) {
		tmp *= i;
		tmp %= 1000000007;
	}
	cout << tmp << endl;
	return 0;
}
