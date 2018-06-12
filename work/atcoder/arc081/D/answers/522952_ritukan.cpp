#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000 * 1000 * 1000 + 7;
char s[2][12345];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	vector<int> go;
	int ptr = 0;
	while (ptr < n) {
		if (s[0][ptr] == s[1][ptr]) {
			go.push_back(1);
			ptr++;
		} else {
			go.push_back(2);
			ptr += 2;
		}
	}
	ll res = 1;
	if (go[0] == 2) {
		res *= 6;
	} else {
		res *= 3;
	}
	for (int i = 1; i < (int)go.size(); i++) {
		if (go[i] == 1) {
			if (go[i - 1] == 1) {
				res *= 2;
			} else {
				res *= 1;
			}
		} else {
			if (go[i - 1] == 1) {
				res *= 2;
			} else {
				res *= 3;
			}
		}
		res %= MOD;
	}
	cout << res << endl;
}

