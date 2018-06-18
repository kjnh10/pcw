#include <bits/stdc++.h>
using namespace std;

vector<int> al[200050];
int visited[200050];
int dist[200050];
queue<int> q;

int main() {
	/* freopen("input.in", "r", stdin);
	freopen("output.o", "w", stdout); */
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		al[a].push_back(b);
		al[b].push_back(a);
	}
	visited[1] = 0;
	dist[1] = 0;
	for (q.push(1); !q.empty(); ) {
	    int v = q.front(); q.pop();
	    for (auto i: al[v]) {
	        if (visited[i]) continue;
	        q.push(i);
	        visited[i] = 1;
	        dist[i] = dist[v] + 1;
	    }
	}
	if (dist[n] == 2) puts("POSSIBLE");
	else puts("IMPOSSIBLE");
}