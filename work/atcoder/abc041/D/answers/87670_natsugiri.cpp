#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M;
int X[555], Y[555];
LL dp[1 << 16];
VI G[16];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d%d", X+i, Y+i), X[i]--, Y[i]--;
    REP (i, M) {
	G[Y[i]].push_back(X[i]);
    }

    dp[0] = 1;
    REP(s, 1 << N) { 
	REP (i, N) if (~s & (1 << i)) {
	    bool ok = true;
	    EACH (e, G[i]) if (~s & (1<<*e)) ok = false;
	    if (ok) dp[s | (1 << i)] += dp[s];
	}
    }

    printf("%lld\n", dp[(1<<N)-1]);


    return 0;
}

