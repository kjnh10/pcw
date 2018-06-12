#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 1010;

int n, m;
vector<pair<int, int> > eds[MAXN];
vector<pair<int, int> > vv[MAXN];
queue<pair<int, int> > qu;
int ans[200010];

vector<int> e[MAXN], _e[MAXN];
int AA[200010],BB[200010];

bool mark[MAXN];
int ord[MAXN], tim;
int to[MAXN],cc;

void dfs(int x){
	if(mark[x])return;
	mark[x] = true;
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		int y = *it;
		dfs(y);
	}
	ord[tim++] = x;
}
void _dfs(int x){
	if(!mark[x])return;
	mark[x] = false;
	to[x] = cc;
	for(vector<int>::iterator it = _e[x].begin(); it != _e[x].end(); it++){
		int y = *it;
		_dfs(y);
	}
}
void scc(){
	for(int i=0; i<n; i++)
		if(!mark[i])
			dfs(i);
	while(tim--){
		int x = ord[tim];
		if(mark[x]){
			_dfs(x);
			cc++;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);

	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(b);
		_e[b].push_back(a);
		eds[a].push_back(make_pair(b, i));
		AA[i] = a;
		BB[i] = b;
	}
	scc();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			vv[j].clear();
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			int u = eds[i][j].first;
			vv[u].push_back(make_pair(1, j));
			qu.push(make_pair(u, 0));
		}
		while (!qu.empty()) {
			int x = qu.front().first;
			int y = qu.front().second;
			qu.pop();
			for (int j = 0; j < (int)eds[x].size(); ++j) {
				int u = eds[x][j].first;
				if (u == i)
					continue;
				if (vv[u].size() >= 2)
					continue;
				if (vv[u].empty() || vv[u][0].second != vv[x][y].second)
					qu.push(make_pair(u, vv[u].size())), vv[u].push_back(make_pair(vv[x][y].first + 1, vv[x][y].second));
			}
		}
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			int u = eds[i][j].first;
			if (vv[u].size() < 2)
				ans[eds[i][j].second] = 0;
			else
				ans[eds[i][j].second] = vv[u][1].first;
		}
	}
	for(int i=0; i<m; i++){
		puts((ans[i] == 0) == (to[AA[i]] != to[BB[i]]) ? "same" : "diff");
	}
	return 0;
}