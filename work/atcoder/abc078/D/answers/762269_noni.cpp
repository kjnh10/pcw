#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <iostream>

using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)	   for(int i = 0; i < (n); ++i)
#define all(c)		   begin(c), end(c)
#define rall(c)		   rbegin(c), rend(c)
#define SZ(a)		   ((ll) a.size())

typedef long long		   ll;
typedef unsigned long long ull;


int main(){
	ll N,z,w;
	scanf("%lld %lld %lld",&N,&z,&w);
	ll a[N];
	rep(i,N) scanf("%lld",&a[i]);
	ll score[N][2];
	score[N-1][0] = abs(a[N-1]-a[N-2]);
	score[N-1][1] = abs(a[N-1]-a[N-2]);
	score[N-2][0] = max(score[N-1][1],abs(a[N-3]-a[N-1]));
	score[N-2][1] = min(score[N-1][0],abs(a[N-3]-a[N-1]));
	ll tmp;
	RFOR(i,N-2,0){
		tmp = abs(a[i-1]-a[N-1]);
		FOR(j,i,N-1) tmp = max(score[j+1][1],tmp);
		score[i][0] = tmp;
		tmp = abs(a[i-1]-a[N-1]);
		FOR(j,i,N-1) tmp = min(score[j+1][0],tmp);
		score[i][1] = tmp;
	}
	tmp = abs(w-a[N-1]);
	FOR(j,0,N-1) tmp = max(score[j+1][1],tmp);
	score[0][0] = tmp;

	printf("%lld",score[0][0]);
	return 0;
}
