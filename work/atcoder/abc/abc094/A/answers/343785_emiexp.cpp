#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, X;

int main()
{
	scanf("%d%d%d", &A, &B, &X);

	bool isok = X >= A && X <= A + B;

	if (isok) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
