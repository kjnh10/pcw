#include <stdio.h>
#include <algorithm>
using namespace std;

int N,L,Q,X[100006],J[100006][17];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d",&X[i]);
	scanf ("%d %d",&L,&Q);

	for (int i=0;i<N-1;i++) J[i][0] = upper_bound(X,X+N,X[i]+L) - X - 1;
	J[N-1][0] = N;
	for (int j=0;j<17;j++) J[N][j] = N;
	for (int i=N-1;i>=0;i--){
		for (int j=1;j<17;j++) J[i][j] = J[J[i][j-1]][j-1];
	}

	while (Q--){
		int a,b; scanf ("%d %d",&a,&b); a--; b--;
		if (a > b) swap(a,b);
		int s = 0;
		for (int i=16;i>=0;i--){
			if (J[a][i] < b) a = J[a][i], s += (1 << i);
		}
		s++;
		printf ("%d\n",s);
	}

	return 0;
}