#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
const int M = 200000;

int f[N + 1];
int dnf[N + 1];
int low[N + 1];
int col[N + 1];
bool book[N + 1];
int fi[N + 1];
int ne[M + 1];
int to[M + 1];
int S[N + 1];
int in[N + 1];
int top;
int n;
int m;
int tot;
int jsq;
int scc;
int A[N + 1];

void add(int u, int v) {
	tot++;
	ne[tot] = fi[u];
	fi[u] = tot;
	to[tot] = v;
}

void Tarjan(int x) {
	book[x] = 1;
	S[++top] = x;
	dnf[x] = low[x] = ++jsq;
	for(int i = fi[x]; i; i = ne[i]) {
		if(!dnf[to[i]]) {
			Tarjan(to[i]);
			low[x] = min(low[x], low[to[i]]);
		}
		else if(book[to[i]]) {
			low[x] = min(low[x], dnf[to[i]]);
		}
	}
	if(dnf[x] == low[x]) {
		int t = 0;
		scc++;
		while(t != x && top) {
			t = S[top--];
			book[t] = 0;
			col[t] = scc;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m); scc = n;
	for(int i = 1; i <= n; i++) scanf("%d", &f[i]);
	for(int i = 1; i <= m; i++) {
		int a;
		int b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	for(int i = 1; i <= n; i++)
		if(!dnf[i])
			Tarjan(i);
	for(int i = 1; i <= n; i++) A[i] = col[i];
	int res = 0;
	for(int i = 1; i <= n; i++) res += A[f[i]] == col[i];
	printf("%d\n", res);
	return 0;
}