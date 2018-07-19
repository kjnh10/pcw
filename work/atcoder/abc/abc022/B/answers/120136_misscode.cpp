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

bool tmp[100000] = {};
signed main() {
	int N; cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (tmp[a] == true) ans++;
		tmp[a] = true;
	}
	cout << ans << endl;
	return 0;
}