#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll Pow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while (b) {
		if (b & 1) {
			res = (res * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

int main()
{
	int N, a;
	bool flag = false;
	cin >> N;
	vector<int> A(N);
	cin >> a;
	if (a) {
		flag = true;
	}
	A[0]++;
	for (int i = 1; i < N; i++) {
		cin >> a;
		if (a == 0) {
			flag = true;
		}
		A[a]++;
	}
	while (!flag && A.back() == 0) {
		A.pop_back();
	}
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (A[i] == 0) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << 0 << endl;
		return 0;
	}
	ll res = 1;
	for (int i = 0; i < n; i++) {
		res = (res * Pow(2, (ll)A[i] * (A[i] - 1) / 2)) % mod;
	}
	for (int i = 1; i < n; i++) {
		res = (res * Pow(((Pow(2, A[i - 1]) + mod - 1) % mod), A[i])) % mod;
	}
	cout << res << endl;
	return 0;
}
