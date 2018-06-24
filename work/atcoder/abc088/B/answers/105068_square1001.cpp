#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int N, a[109];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N, greater<int>());
	int ret = 0;
	for (int i = 0; i < N; i++) ret += a[i] * (i & 1 ? -1 : 1);
	cout << ret << endl;
	return 0;
}