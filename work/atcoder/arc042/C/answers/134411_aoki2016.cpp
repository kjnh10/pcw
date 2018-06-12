#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<functional>
#include<list>
using namespace std;

vector<int>a;
bool used[100000];
int main() {
	int b, c; cin >> b >> c;
	for (int d = 0; d < c; d++) {
		int e; scanf("%d", &e);
		a.push_back(e);
	}
	for (int d = a.size() - 1; d >= 0; d--) {
		if (!used[a[d]-1]) {
			used[a[d]-1] = true;
			cout << a[d] << endl;
		}
	}
	for (int d = 0; d < b; d++) {
		if (!used[d]) {
			cout << d + 1 << endl;
		}
	}
}