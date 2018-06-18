#include "bits/stdc++.h"
using namespace std;


bool isprime(long long int val) {
	if (val <= 1)return false;
	for (long long int i = 2; i*i <= val; i++) {
		if (val%i == 0LL)return false;
	}
	return true;
}


bool f[100002];
int q;

int cnt[100002];

int main() {
	cin >> q;
	for (int i = 2; i <= 100001; i++) {
		f[i] = isprime(i);
	}
	for (int i = 1; i <= 100000; i++) {
		if (f[i] && f[(i + 1)/2]) {
			cnt[i] = 1;
		}
		cnt[i] += cnt[i - 1];
	}
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = cnt[r];
		ans -= cnt[l - 1];
		printf("%d\n", ans);
	}
	return 0;
}