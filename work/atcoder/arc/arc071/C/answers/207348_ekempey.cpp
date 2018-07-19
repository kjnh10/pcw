#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> cnt(26, 1e9);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<int> v(26);
		for (char c : s) {
			v[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			cnt[i] = min(cnt[i], v[i]);
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << string(cnt[i], i + 'a');
	}
}
