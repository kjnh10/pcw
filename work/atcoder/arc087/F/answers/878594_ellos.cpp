#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, vector< vector<int> > &G, vector<int> &S, vector<int> &par) {
	S[R] =1;
	ALL_THE(G[R],it) if(S[*it] == 0) {
		DFS(*it,G,S,par);
		par[*it] =R;
		S[R] +=S[*it];
	}
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(e%2) x =(x*a)%mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int x,y;
		cin >> x >> y;
		G[--x].push_back(--y);
		G[y].push_back(x);
	}

	vector<int> S(N,0), par(N,0);
	DFS(0,G,S,par);
	int c =0;
	for(int i =0; i < N; i++) {
		bool isc =(S[i] >= N-S[i]);
		ALL_THE(G[i],it) if(*it != par[i] && S[*it] > N-S[*it]) isc =false;
		if(isc) c =i;
	}
	for(int i =0; i < N; i++) S[i] =0;
	par[c] =c;
	DFS(c,G,S,par);
	vector<int> A;
	ALL_THE(G[c],it) A.push_back(S[*it]);
	A.push_back(1);
	int M =A.size();

	cat mod =1000000007;
	vector<cat> fac(10000,1), inv(10000,1);
	for(int i =1; i < 10000; i++) fac[i] =(i*fac[i-1])%mod;
	for(int i =1; i < 10000; i++) inv[i] =pw(fac[i],mod-2,mod);
	vector< vector<cat> > cnt(M+1,vector<cat>(N+1,0));
	cnt[0][0] =1;
	for(int i =0; i < M; i++) for(int k =0; k <= A[i]; k++) {
		cat C =(fac[A[i]]*inv[k])%mod*inv[A[i]-k]%mod;
		C =C*fac[A[i]]%mod*inv[A[i]-k]%mod;
		for(int j =0; j <= N-k; j++)
			cnt[i+1][j+k] =(cnt[i+1][j+k]+cnt[i][j]*C)%mod;
	}
	
	cat ans =0;
	for(int i =N; i >= 0; i--) {
		if((N-i)%2) ans =(ans-fac[i]*cnt[M][N-i])%mod;
		else ans =(ans+fac[i]*cnt[M][N-i])%mod;
	}
	for(int i =N-1; i >= 0; i--) {
		if((N-1-i)%2) ans =(ans-fac[i]*cnt[M-1][N-1-i])%mod;
		else ans =(ans+fac[i]*cnt[M-1][N-1-i])%mod;
	}
	ans %=mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
