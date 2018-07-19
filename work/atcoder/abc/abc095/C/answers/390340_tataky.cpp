#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, x, y;
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	c*=2;
	if(a+b<=c) {
		printf("%d\n",x*a+b*y);
		return 0;
	}
	if(c<=min(a,b)) {
		printf("%d\n",max(x,y)*c);
		return 0;
	}
	printf("%d\n",min(x,y)*c+abs(x-y)*(x>y?min(a,c):min(b,c)));
	return 0;
}