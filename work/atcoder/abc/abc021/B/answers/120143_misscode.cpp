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
	int N;
	int a, b; 
	cin >> N >> a >> b;
	tmp[a]++;
	tmp[b]++;
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int z;
		cin >> z;
		if (tmp[z] == true) {
			cout << "NO" << endl;
			return 0;
		}
		tmp[z] = true;
	}
	cout << "YES" << endl;
	return 0;
}