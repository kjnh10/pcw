#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=998244353;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int W[4100][4100];
int B[4100][4100];
char in[2];
int cw(int a,int b,int c,int d){
	return W[c][d]+W[a][b]-W[a][d]-W[c][b];
}
int cb(int a,int b,int c,int d){
	return B[c][d]+B[a][b]-B[a][d]-B[c][b];
}

int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		int p,q;scanf("%d%d%s",&p,&q,in);
		if(in[0]=='W')W[p%(b*2)+1][q%(b*2)+1]++;
		if(in[0]=='B')B[p%(b*2)+1][q%(b*2)+1]++;
	}
	for(int i=1;i<=b*2;i++){
		for(int j=1;j<=b*2;j++){
			W[i+b*2][j]=W[i][j];
			W[i][j+b*2]=W[i][j];
			W[i+b*2][j+b*2]=W[i][j];
			B[i+b*2][j]=B[i][j];
			B[i][j+b*2]=B[i][j];
			B[i+b*2][j+b*2]=B[i][j];
		}
	}
	for(int i=0;i<b*4+1;i++){
		for(int j=0;j<b*4+1;j++){
			W[i][j+1]+=W[i][j];
			B[i][j+1]+=B[i][j];
		}
	}
	for(int i=0;i<b*4+1;i++){
		for(int j=0;j<b*4+1;j++){
			W[j+1][i]+=W[j][i];
			B[j+1][i]+=B[j][i];
		}
	}
	int ret=0;
	for(int i=0;i<2*b;i++){
		for(int j=0;j<2*b;j++){
			ret=max(ret,cw(i,j,i+b,j+b)+cw(i+b,j+b,i+2*b,j+2*b)+cb(i,j+b,i+b,j+2*b)+cb(i+b,j,i+b*2,j+b));
		}
	}
	printf("%d\n",ret);
}