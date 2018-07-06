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
	int N; int num[1000] = {};
	cin >> N;
	int tmp = 0, sum = 0;
	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < N; i++) {
		if (num[i] != 0) tmp++;
		sum += num[i];
	}
	int ans = sum / tmp + !!(sum%tmp);
	cout << ans << endl;
	return 0;
}