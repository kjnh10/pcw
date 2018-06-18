#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;
 
int const MAX_N = 256 * 1024;
 
struct edge {
	int end_v;
	int dst;
	edge(){}
	edge(int end_v, int dst):end_v(end_v),dst(dst) {}
};

vector<edge> e[MAX_N], back_e[MAX_N];
int num, nnew[MAX_N], lst[MAX_N];
long long final_X[MAX_N];

void dfs(int v) {
	nnew[v]=1;
	for (int j=0; j<(int) e[v].size(); j++) {
		int i = e[v][j].end_v;
		if (nnew[i]==0) dfs(i);
		else if (nnew[i]==1) {
			cout<<"No";
			exit(0);
		}
	}
	lst[num]=v;
	num--;
	nnew[v]=2;
}

int const INT_INF = 1000000000;
long long mem_dst[MAX_N];

void dfs_2(int v, long long dst) {
	mem_dst[v] = dst;
	nnew[v] = 1;
	for (int j=0; j<(int) e[v].size(); j++) {
		int i = e[v][j].end_v;
		if (nnew[i] == 0)
			dfs_2(i, dst + e[v][j].dst);
		else if (nnew[i] == 1) {
			if (dst + e[v][j].dst != mem_dst[i]) {
				cout<<"No";
				exit(0);
			}
		}
	}
}

int main() {
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int a,b,dst;
		scanf("%d%d%d",&a,&b,&dst);
		e[a].push_back(edge(b,dst));
		back_e[b].push_back(edge(a,dst));
	}

	num=n;
	for (int i=1; i<=n; i++)
		if (!nnew[i]) dfs(i);

	for (int i=1; i<=n; i++) {
		int v = lst[i];
		for (int j=0; j<(int) back_e[v].size(); j++) {
			int from_v = back_e[v][j].end_v;
			final_X[v] = max(final_X[v], final_X[from_v] + back_e[v][j].dst);
		}
	}
	for (int i=1; i<=n; i++)
		if (final_X[i] > INT_INF) {
			cout<<"No";
			exit(0);
		}

	for (int i=1; i<=n; i++) nnew[i] = 0;
	for (int i=1; i<=n; i++)
		if (!nnew[lst[i]])
			dfs_2(lst[i], 0);

	cout<<"Yes";
    return 0;
}  
