#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<random>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
#include<string.h>
#include<iostream>
using namespace std;

int a[3][3];
signed main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		set<int>S;
		for (int j = 0; j < 3; j++) {
			S.insert(a[i][j] - a[i + 1][j]);
		}
		if (S.size() > 1) { puts("No"); return 0; }
	}
	for (int i = 0; i < 2; i++) {
		set<int>S;
		for (int j = 0; j < 3; j++) {
			S.insert(a[j][i] - a[j][i+1]);
		}
		if (S.size() > 1) { puts("No"); return 0; }
	}
	puts("Yes");
}