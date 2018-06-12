#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

signed main() {
	int n; scanf("%d", &n);
	int a = 0, b = 0, c = 0;
	rep(i, n) {
		int A; scanf("%d", &A);
		if (A % 4 == 0)a++;
		else if (A % 2 == 0)b++;
		else c++;
	}
	//aとcを交互に並べ
	if (c == a + 1) {
		if (b == 0)puts("Yes");
		else puts("No");
	}
	else puts(a >= c ? "Yes" : "No");
}