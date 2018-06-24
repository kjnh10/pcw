#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(begin(a), end(a), greater<int>());

	int s = a.front();
	int min = a.front() - a.back();
	int k = n - 1;
	for (int i = 1; i < n; i++) {
		int d = abs(a[i] - s / 2);
		if (d < min) {
			min = d;
			k = a[i];
		}
	}

	printf("%d %d\n", s, k);
	return 0;
}