#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int MOD = 998244353;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 200100;
int n;
int dp[N][3][3];

void solveSmall(string s) {
	set<string> used;
	vector<string> q;
	q.push_back(s);
	used.insert(s);
	for (int i = 0; i < (int)q.size(); i++) {
		s = q[i];
		string w;
		for (int j = 0; j < (int)s.length() - 1; j++) {
			if (s[j] == s[j + 1]) continue;
			w = s;
			char c = 'a';
			while(c == s[j] || c == s[j + 1]) c++;
			w[j] = w[j + 1] = c;
			if (used.count(w) > 0) continue;
			used.insert(w);
			q.push_back(w);
		}
	}
	printf("%d\n", (int)used.size());
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string w;
	cin >> w;
	n = w.length();

	bool bad = 1;
	for (int i = 0; i < n; i++)
		bad &= w[0] == w[i];
	if (bad) {
		printf("1\n");
		return 0;
	}

	if (n <= 5) {
		solveSmall(w);
		return 0;
	}

	for (int x = 0; x < 3; x++)
		dp[1][x][x] = 1;
	for (int i = 1; i < n; i++) {
		for (int x = 0; x < 3; x++)
			for (int s = 0; s < 3; s++)
				for (int y = 0; y < 3; y++) {
					if (x == y) continue;
					int ns = (s + y) % 3;
					dp[i + 1][y][ns] = add(dp[i + 1][y][ns], dp[i][x][s]);
				}
	}

	int s = 0;
	for (int i = 0; i < n; i++) {
		s += (int)(w[i] - 'a');
	}
	s %= 3;

	int res = 1;
	for (int i = 1; i < n; i++)
		res = mult(res, 3);
	for (int x = 0; x < 3; x++)
		res = sub(res, dp[n][x][s]);

	bool ok = true;
	for (int i = 0; i < n - 1; i++)
		ok &= w[i] != w[i + 1];
	if (ok) res = add(res, 1);
	printf("%d\n", res);

	return 0;
}
