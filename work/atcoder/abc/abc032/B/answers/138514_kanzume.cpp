#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cctype>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	set<string>s;
	string ss;
	cin >> ss >> n;
	for (int i = 0; i < ss.size(); i++) {
		if (i + n > ss.size())break;
		s.insert(ss.substr(i, n));
	}
	cout << s.size() << endl;
	return 0;
}