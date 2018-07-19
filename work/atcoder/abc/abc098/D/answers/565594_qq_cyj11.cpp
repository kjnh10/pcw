#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int n;
long long res;
int a[N + 1];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int l = 1;
	int s = a[1];
	for(int i = 2; i <= n + 1; i++) {
		while(s & a[i]) {
			res += i - l;
			s ^= a[l];
			l++;
		}
		s |= a[i];
	}
	cout << (res + 1LL * (n - l + 1) * (n - l + 2) / 2) << endl;
	return 0;
}