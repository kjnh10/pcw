#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int a[100000];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];

	map<int, int> mp;
	for (int i = 0; i < N; i++)
		mp[a[i]]++;

	int ans = 0;
	for (auto p: mp) {
		int x = p.first;
		int n = p.second;
		if (n < x) ans += n;
		else ans += n - x;
	}

	cout << ans << endl;
}
