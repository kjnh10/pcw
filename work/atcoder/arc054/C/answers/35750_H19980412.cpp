#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define mod 1000000007
int main(){
	double L,X,Y,S,D;
	scanf("%lf%lf%lf%lf%lf",&L,&X,&Y,&S,&D);
	double ret;
	if(S<=D) ret = D-S;
	else ret = D-S+L;
	ret = ret/(X+Y);
	if(X < Y){
		double ret2;
		if(S>=D) ret2 = S-D;
		else ret2=S-D+L;
		ret2 = ret2/(Y-X);
		ret = min(ret,ret2);
	}
	printf("%.10f\n",ret);
}