#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 1e9
main(){
	int n;
	scanf("%d",&n);
	double x[1010],y[1010],c[1010];
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf",&x[i],&y[i],&c[i]);
	}
	
	double lb=0,ub=1e9;
	for(int t=0;t<1000;t++){
		double mid=(lb+ub)/2;
		double x0=-INF,x1=INF,y0=-INF,y1=INF;
		for(int i=0;i<n;i++){
			x0=max(x0,x[i]-mid/c[i]);
			x1=min(x1,x[i]+mid/c[i]);
			y0=max(y0,y[i]-mid/c[i]);
			y1=min(y1,y[i]+mid/c[i]);
		}
		if(x0<=x1 && y0<=y1)ub=mid;
		else lb=mid;
	}
	printf("%.10f\n",ub);
}