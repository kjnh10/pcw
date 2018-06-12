#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double xd,yd;

double calc(double a,double c){
	return abs(a * xd + yd + c) / sqrt(a * a + 1);
}

int main(){
	int x,y,n,xs[10],ys[10];
	double mi = 1000.0;
	scanf("%d %d %d",&x,&y,&n);
	xd = (double)x;
	yd = (double)y;
	for(int i = 0;i < n;i++){
		scanf("%d %d",&xs[i],&ys[i]);
	}
	for(int i = 0;i < n;i++){
		double a = (double)(ys[(i + 1) % n] - ys[i]) / (double)(xs[(i + 1) % n] - xs[i]);
		mi = min(mi,calc(-a,(double)xs[i] * a - (double)ys[i]));
	}
	printf("%.9f\n",mi);
	return 0;
}