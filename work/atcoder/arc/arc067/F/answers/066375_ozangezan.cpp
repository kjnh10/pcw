#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
long long x[5100];
int C[5100][210];
int segtree[210][16384];
int query(int a,int b,int c,int d,int e,int f){
	if(d<a||b<c)return 0;
	if(c<=a&&b<=d)return segtree[f][e];
	return max(query(a,(a+b)/2,c,d,e*2,f),query((a+b)/2+1,b,c,d,e*2+1,f));
}

int n;
int m;
long long ans[5100];
int tmp[210];
void solve(int a,int b,int c,int d){
	if(b<=a)return;
	int M=(a+b)/2;
	int lm=max(M,c);
	for(int i=0;i<m;i++){
		tmp[i]=query(0,8191,M,lm,1,i);
	}
	int at=c;
	long long best=-inf;
	for(int i=c;i<=d;i++){
		if(lm>i)continue;
		long long cur=x[M]-x[i];
		for(int j=0;j<m;j++)cur+=tmp[j];
		if(best<cur){
			best=cur;
			at=i;
		}
		if(i<d){
			for(int j=0;j<m;j++)tmp[j]=max(tmp[j],C[i+1][j]);
		}
	}
	ans[M]=best;
//	printf("%d: %d %lld\n",M,at,best);
	solve(a,M,c,at);
	solve(M+1,b,at,d);
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	n=a;m=b;
	for(int i=0;i<a-1;i++)scanf("%lld",x+i+1);
	for(int i=1;i<a;i++){
		x[i]+=x[i-1];
	}
	for(int i=0;i<a;i++)for(int j=0;j<b;j++){
		scanf("%d",&C[i][j]);
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++)segtree[i][j+8192]=C[j][i];
		for(int j=8191;j>0;j--)segtree[i][j]=max(segtree[i][j*2],segtree[i][j*2+1]);
	}

	solve(0,n,0,n-1);
	long long ret=-inf;
	for(int i=0;i<a;i++)ret=max(ret,ans[i]);
		printf("%lld\n",ret);
}