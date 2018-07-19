#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	cout << s[0] << n - 2 << s[n - 1] << endl;

	return 0;
}