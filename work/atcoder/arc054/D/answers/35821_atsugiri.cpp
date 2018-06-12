#include<cmath>
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

double P;

double f(double x) {
    return - (P / pow(2.0, x/1.5) + x);
}


const double GR = (sqrt(5) - 1.0) / 2.0; // GR == 0.618
double argmax() {
    double lo = 0, hi = 1e100;
    double x = hi - GR * (hi - lo), y = lo + GR * (hi - lo);
    double vx = f(x), vy = f(y);
    for (int i=0; i<600; i++) {
	if (vx < vy) { lo = x; x = y; vx = vy; y = lo + GR * (hi - lo); vy = f(y); }
	else { hi = y; y = x; vy = vx; x = hi - GR * (hi - lo); vx = f(x); }
    }
    return (x+y)/2.0;
}


int main() {
    scanf("%lf", &P);
    printf("%.9f\n", -f(argmax()));

    return 0;
}
