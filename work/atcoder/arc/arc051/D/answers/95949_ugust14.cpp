#include <stdio.h>

int main()
{
	int k; scanf ("%d",&k);
	int a = 2, b = 1; k--;
	while (k--){
		int c = a + b;
		b = a; a = c;
	}
	printf ("%d %d\n",a,b);

	return 0;
}