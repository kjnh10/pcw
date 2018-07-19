#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long double L, X, Y, S, D, S1, D1, S2, D2;
int main() {
	cin >> L >> X >> Y >> S >> D;
	S1 = S; S2 = S; D1 = D; D2 = D;
	if (S1 > D1)D1 += L;
	if (S2 < D2)S2 += L;
	long double A1 = (D1 - S1) / (X + Y);
	long double A2 = (D2 - S2) / (X - Y);
	if (A2 < 0)A2 = 1000000000;
	printf("%.12Lf\n", min(A1, A2));
	return 0;
}