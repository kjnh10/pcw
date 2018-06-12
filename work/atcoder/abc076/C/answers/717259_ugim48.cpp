#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
struct edge { int v, w; };

bool check(string s, string t) {
	int N = s.length(), M = t.length();
	for (int l = 0; l + M <= N; l++) {
		bool ok = true;
		rep(i, M)
			if (s[l + i] == '?' || (s[l + i] == t[i]));
			else ok = false;
		if (ok) return true;
	}
	return false;
}

int main() {
	string s, t; cin >> s >> t;
	if (!check(s, t)) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	int N = s.length();
	rep(i, N) if (s[i] == '?')
		for (char c = 'a'; ; c++) {
			s[i] = c;
			if (check(s, t)) break;
		}
	cout << s << endl;
}
