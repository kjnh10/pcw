#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<set>
#include<limits.h>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<functional>
#include<stack>
#include<deque>
#include<queue>
using namespace std;

signed main() {
	int n; cin >> n;
	set<int>S;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		S.insert(a);
	}
	cout << S.size() << endl;
}