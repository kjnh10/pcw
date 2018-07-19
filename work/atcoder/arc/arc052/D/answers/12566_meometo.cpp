#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double x[101010],r[101010],h[101010];

double calc(double a){
	double ret=0;
	for(int i=0;i<n;i++){
		if(x[i]+h[i]<=a)continue;
		else{
			double l=(a<=x[i]?h[i]:x[i]+h[i]-a);
			ret+=M_PI/3*r[i]*r[i]/h[i]/h[i]*l*l*l;
		}
	}
	return ret;
}

main(){
	int q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%lf%lf%lf",&x[i],&r[i],&h[i]);
	for(int i=0;i<q;i++){
		double a,b;
		scanf("%lf%lf",&a,&b);
		printf("%.10f\n",calc(a)-calc(b));
	}
}