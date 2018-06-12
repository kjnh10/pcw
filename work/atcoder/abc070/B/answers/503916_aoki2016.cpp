#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<cmath>
#include<unordered_set>
using namespace std;

signed main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << max(0, min(d, b) - max(a, c)) << endl;
}