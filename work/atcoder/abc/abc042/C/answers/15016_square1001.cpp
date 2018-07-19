#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int N, M, a; bool z[11];
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> a, z[a] = 1;
	for (int i = N; ; i++) {
		string s = to_string(i);
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (z[s[i] - 48]) flag = false;
		}
		if (flag) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}