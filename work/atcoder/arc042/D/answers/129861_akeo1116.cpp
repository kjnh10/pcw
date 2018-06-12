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
#include <functional>
#include <utility>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	cout<<fixed<<setprecision(20);
	int x,y;
	int N;
	int xx[10]={},yy[10]={};
	double mini=MOD;
	cin>>x>>y;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>xx[i]>>yy[i];
	}
	for(int i=0;i<N;i++){
		int xa=xx[i],ya=yy[i];
		int xb=xx[(i+1)%N],yb=yy[(i+1)%N];

		int S=abs((x-xa)*(yb-ya)-(y-ya)*(xb-xa));
		double L=sqrt(1.*(xb-xa)*(xb-xa)+1.*(yb-ya)*(yb-ya));

		//printf("%d %d %d %d\n",x-xa,yb-ya,y-ya,xb-xa);
		mini=min(mini,S/L);
	}
	cout<<mini<<endl;
	return 0;
}