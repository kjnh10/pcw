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

int ddx[3]={0,1,1};
int ddy[3]={1,0,1};
int mem[100][100]={};
char S[100][101];
int H,W;
int judge(int x,int y);

int main(){
	cin>>H>>W;
	for(int i=0;i<H;i++){
		cin>>S[i];
	}
	if(judge(0,0)==1)
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
	return 0;
}

int judge(int x,int y){
	if(x>(H-1) || y>(W-1) || S[x][y]=='#')
		return 1;
	else if(mem[x][y]!=0)
		return mem[x][y];

	int result=-1;
	for(int i=0;i<3;i++){
		if(judge(x+ddx[i],y+ddy[i])==-1)
			result=1;
	}
	return mem[x][y]=result;
}