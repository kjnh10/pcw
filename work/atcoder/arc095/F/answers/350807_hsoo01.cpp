#include<bits/stdc++.h>
using namespace std;

int n, dist[2][100005];

vector<int> adj[100005], v, a, p1, p2;

void calc (int I, int C, int P) {
	for(auto &T : adj[C]) {
		if(T == P) continue;
		dist[I][T] = dist[I][C] + 1;
		calc(I, T, C);
	}
}

bool getp (int C, int P, int O) {
	if(C == O) {v.push_back(C); return true;}
	for(auto &T : adj[C]) {
		if(T == P) continue;
		if(getp(T, C, O)) {v.push_back(C); return true;}
	}
	return false;
}

void solve (vector<int> &A) {
	A.push_back(1);
	int S = 1;
	for(int i=0;i<(int)a.size();i++) {
		for(int j=1;j<=a[i];j++) A.push_back(S+j+1);
		A.push_back(S+1);
		S += a[i]+1;
	}
	A.push_back(n);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	int x = 0, y = 0;
	calc(0, 1, 0);
	for(int i=1;i<=n;i++) if(dist[0][i] > dist[0][x]) x=i;
	calc(1, x, 0);
	for(int i=1;i<=n;i++) if(dist[1][i] > dist[1][y]) y=i;
	getp(x, 0, y);
	int S = (int)v.size()-1;
	for(int i=1;i+1<(int)v.size();i++) {
		int T = (int)adj[v[i]].size()-2;
		a.push_back(T);
		S += T;
	}
	if(S != n-1) {puts("-1"); return 0;}
	solve(p1);
	reverse(a.begin(), a.end());
	solve(p2);
	bool F = false;
	for(int i=0;i<n;i++) {
		if(p1[i] > p2[i]) {F = true; break;}
		if(p1[i] < p2[i]) break;
	}
	if(F) swap(p1,p2);
	for(int i=0;i<n;i++) {
		printf("%d ",p1[i]);
	}
	puts("");
}
