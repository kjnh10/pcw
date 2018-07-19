#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

vector<int> G[100100], L;

void proc()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if (N == 2) {
		puts("1 2");
		return;
	}
	if (N == 3) {
		puts("1 2 3");
		return;
	}
	vector<int> st;
	int x = 1;
	for (int i = 1; i <= N; i++) if (G[i].size() > 1){
		int c = 0;
		for (auto &y : G[i]) if (G[y].size() > 1) c++;
		if (c > 2) {
			puts("-1");
			return;
		}
		if (c == 1) {
			st.push_back(i);
		}
		x = i;
	}

	if (st.empty()) {
		st.push_back(x);
	}

	vector<int> ans; ans.push_back(N + 1);
	for (int s : st) {
		vector<int> now;
		now.push_back(1);
		int c = 2, last = -1;
		while (1) {
			int nxt = -1, f = 0;
			for (auto &y : G[s]) if (y != last){
				if (G[y].size() == 1) f++;
				else nxt = y;
			}
			if (last == -1) f--;
			if (nxt == -1) {
				for (int k = 1; k <= f-1; k++) now.push_back(k + c);
				now.push_back(c); c++; c += f-1;
				now.push_back(c); c++;
			}
			else {
				for (int k = 1; k <= f; k++) now.push_back(k + c);
				now.push_back(c); c++; c += f;
			}
			if (nxt == -1) break;
			last = s;
			s = nxt;
		}

		if (ans > now)
			ans = now;
	}

	for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i],i+1<ans.size()?' ':'\n');
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}