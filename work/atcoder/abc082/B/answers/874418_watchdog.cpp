#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	string s, t; cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	if (s < t) cout << "Yes\n";
	else cout << "No\n";
	return 0; 
} 