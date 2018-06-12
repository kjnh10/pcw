#include<bits/stdc++.h>
using namespace std;
const int inf = 2e9;
int n, mn = inf;

long long ans;

int main()
{
	scanf("%d",&n);
	bool flag = false;
	for(int i=1;i<=n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		ans += A;
		if(A > B) {flag = 1; mn = min(mn, B);}
	}
	printf("%lld\n",(flag?ans-mn:0));
}
