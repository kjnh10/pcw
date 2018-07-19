#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

signed main(){
	int n,a,b,mi = 1000000001,ma = 0,sum = 0;
	double ave;
	cin >> n >> a >> b;
	for(int i = 0;i < n;i++){
		int s;
		scanf("%lld",&s);
		mi = min(s,mi);
		ma = max(s,ma);
		sum += s;
	}
	ave = (double)sum / (double)n;
	if(mi == ma){
		cout << -1 << endl;
		return 0;
	}
	double p = (double)b / (double)(ma - mi),q = (double)a - ave * p;
	printf("%.9f %.9f\n",p,q);
	return 0;
}