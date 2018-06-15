#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int a, b; cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; i++) {
		string s = to_string(i);
		string s1 = s;
		reverse(s.begin(), s.end());
		ans += (s1 == s);
	}
	cout << ans;
	
	return 0;
}