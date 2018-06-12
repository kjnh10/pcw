#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <map>
#include <functional>
#include <cmath>
using namespace std;
#pragma warning(disable: 4996)
string S; int minx;
int main() {
	cin >> S;
	minx = S.size();
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] != S[i + 1]) { minx = min(minx, max((int)S.size() - i - 1, i + 1)); }
	}
	cout << minx << endl;
	return 0;
}