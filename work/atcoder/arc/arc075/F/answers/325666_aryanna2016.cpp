#include<bits/stdc++.h>
using namespace std;
int l;
long long int p10[22],w[22],now;
int cc(int i,int t){
	if(i==0){
		return 9-t;
	}
	return 10-labs(t);
}
void dfs(int i,long long int dif,long long int q){
	long long int bes = 0;
	for(int j=i; j<l; j++)
		bes += w[j] * 9;
	if(dif > bes || dif < -bes)return;

	if(i == l){
		now += q;
		return;
	}
	for(int t = (i==0?0:-9); t <= 9; t++){
		dfs(i+1, dif - t * w[i], q * cc(i, t));
	}
}
long long int calc(int len,long long int dif){
	p10[0] = 1;
	for(int i=1; i<len; i++)
		p10[i] = p10[i-1] * 10;
	l = 0;
	for(int i=len-1,j=0; i>j; i--,j++)
		w[l++] = p10[i] - p10[j];
	now = 0;
	dfs(0,dif,1);
	return now;
}
int main(){
	long long int tot = 0;
	int D;
	scanf("%d",&D);
	for(int len = 2; len <= 18; len++){
		tot += calc(len, D) * ((len % 2) ? 10 : 1);
	}
	cout << tot << endl;
	return 0;
}
