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
long long X, Y, C = 0;
int main() {
	cin >> X >> Y;
	while (X <= Y) { C++; X *= 2; }
	cout << C << endl;
	return 0;
}