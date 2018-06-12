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
	string S;
	cin >> S;
	int N =S.length();
	int minp =N;
	for(int l =1; l < N; l++) if(N%l == 0) {
		bool bad =true;
		for(int i =0; i < N; i++) if(S[i] != S[i%l]) bad =false;
		if(bad) {minp =l; break;}
		}
	if(minp == N) {
		cout << "1\n1\n";
		return 0;}
	if(minp == 1) {
		cout << N << "\n1\n";
		return 0;}
	cout << "2\n";
	long long mod =1000000007, p =2641;
	vector<long long> H(N+1,0),pp(N+1,1);
	for(int i =0; i < N; i++) {
		H[i+1] =(H[i]*p+S[i]-'a')%mod;
		pp[i+1] =(pp[i]*p)%mod;}
	vector<int> badl(N,0),badr(N,0);
	for(int l =1; l < N; l++) {
		int a =l; // [a..a+l)
		long long H0 =H[l];
		while(a+l <= N) {
			long long H1 =(H[a+l]-pp[l]*H[a])%mod;
			if((H1-H0)%mod != 0) break;
			badl[a+l-1] =1;
			a +=l;}
		}
	for(int l =1; l < N; l++) {
		int a =N-l*2;
		long long H0 =(H[N]-pp[l]*H[N-l])%mod;
		while(a >= 0) {
			long long H1 =(H[a+l]-pp[l]*H[a])%mod;
			if((H1-H0)%mod != 0) break;
			badr[a] =1;
			a -=l;}
		}
	int ans =0;
	for(int i =0; i < N-1; i++) if(badl[i] == 0 && badr[i+1] == 0) ans++;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing
