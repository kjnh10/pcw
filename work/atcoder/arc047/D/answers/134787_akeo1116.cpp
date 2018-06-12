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
	int N;
	int x[100000]={},y[100000]={};
	int X[100000]={},Y[100000]={};
	int Xmax=-1*INF,Xmin=INF,Ymax=-1*INF,Ymin=INF;
	int D=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>x[i]>>y[i];
		X[i]=x[i]+y[i];
		Y[i]=x[i]-y[i];
		Xmax=max(Xmax,X[i]);
		Xmin=min(Xmin,X[i]);
		Ymax=max(Ymax,Y[i]);
		Ymin=min(Ymin,Y[i]);
	}
	D=max(Xmax-Xmin,Ymax-Ymin);
	int Px[2]={Xmax-D/2,Xmin+D/2},Py[2]={Ymax-D/2,Ymin+D/2};
	//printf("Px=%d %d,Py=%d %d\n",Px[0],Px[1],Py[0],Py[1]);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			int tes=(Px[i]+Py[j])/2;
			int ket=(Px[i]-Py[j])/2;
 			bool flag=0;
			int dis=abs(x[0]-tes)+abs(y[0]-ket);
			for(int k=1;k<N;k++){
				if(abs(x[k]-tes)+abs(y[k]-ket)!=dis)
					flag=1;
			}
			if(!flag){
				printf("%d %d\n",tes,ket);
				return 0;
			}
		}
	}

	return 0;
}