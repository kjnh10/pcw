#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <iomanip>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int h, w;
int dp[2000][2000] = {};
int mape[2000][2000] = {};
int solve(int h, int w) {
	if (dp[h][w]) return dp[h][w];
	int ans = 2;
	if (mape[h + 1][w] == false) {
		if (solve(h + 1, w) == 2) ans = 1;
	}
	if (mape[h][w + 1] == false) {
		if (solve(h, w + 1) == 2) ans = 1;
	}
	if (mape[h + 1][w + 1] == false) {
		if (solve(h + 1, w + 1) == 2) ans = 1;
	}
	return dp[h][w] = ans;
}
int main() {
	cin >> h >> w;
	REP(i, h) {
		string s;
		cin >> s;
		REP(q, w) {
			if (s[q] == '#') {
				mape[i][q] = true;
			}
		}
	}
	for (int i = 0;i < max(h,w)+1;++i) {
		mape[h][i] = true;
		mape[i][w] = true;
	}
	if (solve(0,0) == 1) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
	return 0;
}