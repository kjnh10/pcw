#include <stdio.h>

long long d[5001],p[5001];

int main()
{
	int N,A;
	scanf ("%d %d",&N,&A);
	d[2500] = 1;

	for (int i=0;i<N;i++){
		int x; scanf ("%d",&x); x -= A;
		for (int j=0;j<=5000;j++) p[j] = 0;
		for (int j=0;j<=5000;j++) if (d[j]){
			p[j] += d[j];
			p[j+x] += d[j];
		}
		for (int j=0;j<=5000;j++) d[j] = p[j];
	}
	printf ("%lld\n",d[2500]-1);

	return 0;
}