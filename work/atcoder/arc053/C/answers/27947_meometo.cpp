#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

main(){
	int h,w;
	scanf("%d%d",&h,&w);
	printf("%d\n",(h-1)*w+h*(w-1));
}