#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, Q, Xi[101], Ri[101], Hi[101];
const double PI = acos(-1);

double F(double x, double h, double r)
{
	return PI * r * r * (x * x * x / (3 * h * h) - x * x / h + x);
}

double solve(int X, int R, int H, int A, int B)
{
	int Xlo = X, Xhi = X + H;
	if (B <= Xlo || Xhi <= A) return 0.0;
	if (A <= Xlo && Xhi <= B) {
		return (double)R * R * PI * H / 3;
	}
	A = max(A, Xlo);
	B = min(B, Xhi);
	return F(B - Xlo, H, R) - F(A - Xlo, H, R);
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) scanf("%d%d%d", Xi + i, Ri + i, Hi + i);
	for (; Q--;) {
		int A, B;
		scanf("%d%d", &A, &B);
		double ans = 0;
		for (int i = 0; i < N; ++i) ans += solve(Xi[i], Ri[i], Hi[i], A, B);
		printf("%.10f\n", ans);
	}
	return 0;
}
