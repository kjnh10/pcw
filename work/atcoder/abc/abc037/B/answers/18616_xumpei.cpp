#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < q; i++) {
		int l, r, t;
		scanf("%d %d %d", &l, &r, &t);

		for (int i = l; i <= r; i++)
			a[i - 1] = t;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}