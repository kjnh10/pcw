#include <bits/stdc++.h>
using namespace std;
//メモ化再帰
int SA,SB;
int a[1010],b[1010];
int dp[1010][1010];
//ta:A山の枚数,tb:B山の枚数,返すのはスコア
int rec(int ta,int tb){
	int res;
	if(dp[ta][tb]!=-1) return dp[ta][tb];
	int turn = ((ta+tb)%2)*-2+1;
	if(ta==SA&&tb==SB){
		return 0;
	}else
	if(ta==SA){
		res = rec(ta,tb+1)+b[tb]*turn;
	}else 
	if(tb==SB){
		res = rec(ta+1,tb)+a[ta]*turn;
	}else 
	if(turn==1){
		res = max(rec(ta+1,tb)+a[ta],rec(ta,tb+1)+b[tb]);
	}else{
		res = min(rec(ta+1,tb)-a[ta],rec(ta,tb+1)-b[tb]);
	}
	dp[ta][tb]=res;

	return res;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&SA,&SB);
	long long sum=0;
	for (int i = 0; i < SA; ++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for (int i = 0; i < SB; ++i)
	{
		scanf("%d",&b[i]);
		sum+=b[i];
	}
	printf("%lld\n",(rec(0,0)+sum)/2);
	return 0;
}