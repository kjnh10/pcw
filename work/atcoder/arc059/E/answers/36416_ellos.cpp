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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,C;
	cin >> N >> C;
	vector<int> A(N),B(N);
	for(int i =0; i < N; i++) cin >> A[i];
	for(int i =0; i < N; i++) cin >> B[i];
	long long mod =1000000007;
	vector< vector<long long> > X(500,vector<long long>(C+1,0));
	for(int i =1; i < 500; i++) {
		X[i][0] =1;
		for(int j =1; j <= C; j++) X[i][j] =(X[i][j-1]*i)%mod;}
	for(int i =0; i <= C; i++) for(int j =1; j < 500; j++) X[j][i] =(X[j-1][i]+X[j][i])%mod;
	vector< vector<long long> > ans(C+1,vector<long long>(N+1,0));
	ans[0][0] =1;
	for(int i =0; i < N; i++) for(int c =0; c <= C; c++) for(int d =0; d <= C-c; d++) {
		long long x =(X[B[i]][d]-X[A[i]-1][d])%mod;
		ans[c+d][i+1] =(ans[c+d][i+1]+ans[c][i]*x)%mod;}
	if(ans[C][N] < 0) ans[C][N] +=mod;
	cout << ans[C][N] << "\n";
	return 0;}

// look at my code
// my code is amazing
