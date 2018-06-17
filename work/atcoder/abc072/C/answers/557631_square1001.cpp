#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, c[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a, c[a]++;
	int ret = 0;
	for (int i = 0; i <= 100000; i++) ret = max(ret, c[i] + c[i + 1] + c[i + 2]);
	cout << ret << endl;
	return 0;
}