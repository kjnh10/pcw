#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int A[5050][5050], B[5050][5050], P[5050], N;

void solve(){
	int K;
	scanf("%d%d", &N, &K);
	for(int i=1;i<=N;i++)scanf("%d", P+i);
	A[0][0] = 1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=K;j++)A[i][j] = A[i-1][j];
		for(int j=P[i];j<=K;j++)A[i][j] |= A[i-1][j-P[i]];
	}
	B[N+1][0] = 1;
	for(int i=N;i;i--){
		for(int j=0;j<=K;j++)B[i][j] = B[i+1][j];
		for(int j=P[i];j<=K;j++)B[i][j] |= B[i+1][j-P[i]];
	}
	int ans = 0;
	for(int i=1;i<=N;i++){
		int l = max(0, K - P[i]);
		int r = K - 1;
		vector <int> v;
		for(int j=K;j>=0;j--)if(A[i-1][j])v.pb(j);
		int ok = 0;
		for(int j=0, a=0;j<=K;j++)if(B[i+1][j]){
			while(a < sz(v) && v[a] + j > r)++a;
			if(a < sz(v) && v[a] + j >= l){
				ok = 1; break;
			}
		}
		ans += !ok;
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}