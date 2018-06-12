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
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000009;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int dp[3100][3100];
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	dp[0][0]=1;
	for(int i=0;i<=f;i++){
		for(int j=0;j<=i;j++){
			if(!dp[i][j])continue;
			if(i+a*100<=f)dp[i+a*100][j]=1;
			if(i+b*100<=f)dp[i+b*100][j]=1;
			if(i+c<=f)dp[i+c][j+c]=1;
			if(i+d<=f)dp[i+d][j+d]=1;
		}
	}
	int bb=100*a;
	int bs=0;
	for(int i=1;i<=f;i++){
		for(int j=0;j<=i;j++){
			if(dp[i][j]&&e*i>=(e+100)*j){
				if(j*bb>=i*bs){
					bb=i;bs=j;
				}
			}
		}
	}
	printf("%d %d\n",bb,bs);
}