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

double L, X, Y, S, D;
int main() {

    scanf("%lf%lf%lf%lf%lf", &L, &X, &Y, &S, &D);

    D -= S;
    while (D < 0) D += L;

    double ans = D / (X + Y);
    if (X < Y) {
	amin(ans, (L - D) / (Y - X));
    }

    printf("%.9f\n", ans);


    return 0;
}
