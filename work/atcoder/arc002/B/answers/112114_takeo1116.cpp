#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int Y,M,D;
	scanf("%d/%d/%d",&Y,&M,&D);
	for(;1;D++){
		bool uru=0;
		if(!(Y%4)) uru=1;
		if(!(Y%100)) uru=0;
		if(!(Y%400)) uru=1;
		if(uru) month[2]=29;
		else month[2]=28;

		if(D>month[M]){
			D=1;
			M++;
		}
		if(M>12){
			M=1;
			Y++;
		}
		if(!(Y%M) && !((Y/M)%D)){
			break;
		}
	}
	printf("%02d/%02d/%02d\n",Y,M,D);
	return 0;
}