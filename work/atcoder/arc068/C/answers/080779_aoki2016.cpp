#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
#include<map>
#include<unordered_map>
#include<unordered_set>
#define int long long
using namespace std;

signed main() {
	int a; cin >> a;
	int ans = a / 11*2;
	a -= a / 11 * 11;
	if (a > 6)ans += 2;
	else if (a != 0)ans++;
	cout << ans << endl;
}