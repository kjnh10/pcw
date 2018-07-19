#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int W, A, B; scanf("%d%d%d", &W, &A, &B);
	if (A > B) swap(A, B);

	if (B <= A + W) return !printf("0");
	printf("%d", B - A - W);
}