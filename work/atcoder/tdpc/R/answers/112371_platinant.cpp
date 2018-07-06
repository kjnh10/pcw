#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
const int MAX_N = 310;

bool chk[MAX_N];
bool a[MAX_N][MAX_N];

int st[MAX_N],sz;
int ID[MAX_N],cnt[MAX_N],M;

bool b[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void dfs(int v){
	chk[v]=1;
	for(int i=1;i<=N;i++){
		if(!a[v][i])continue;
		if(chk[i])continue;
		dfs(i);
	}
	st[sz++]=v;
}

void dfs2(int v,int c){
	ID[v]=c;
	cnt[c]++;
	for(int i=1;i<=N;i++){
		if(!a[i][v])continue;
		if(ID[i])continue;
		dfs2(i,c);
	}
}

int solve(int x,int y){
	if(x>y)swap(x,y);
	int& ret=dp[x][y];
	if(~ret)return ret;
	ret=0;
	if(b[x][y])ret=max(ret,solve(y,y));
	for(int i=y+1;i<=M;i++){
		if(b[x][i])ret=max(ret,solve(y,i)+cnt[i]);
	}
	for(int i=y+1;i<=M;i++){
		if(b[y][i])ret=max(ret,solve(x,i)+cnt[i]);
	}

	return ret;
}

int main(){

	memset(dp,-1,sizeof(dp));

	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(int i=1;i<=N;i++){
		if(chk[i])continue;
		dfs(i);
	}

	while(sz--){
		if(!ID[st[sz]])dfs2(st[sz],++M);
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(a[i][j]&&ID[i]!=ID[j])b[ID[i]][ID[j]]=1;
		}
	}

	for(int i=1;i<=M;i++){
		b[0][i]=1;
	}

	printf("%d\n",solve(0,0));
	return 0;
}
