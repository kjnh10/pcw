#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	if (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0])
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}