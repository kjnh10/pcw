#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int n,cnt,ch[maxn][2];
ll l,sg;
char s[maxn];

ll lowbit(ll a){
	return a&(-a);
}
void insert(){
	int rt=1;
	for(int i=0;s[i];++i){
		if(!ch[rt][s[i]-'0'])
			ch[rt][s[i]-'0']=++cnt;
		rt=ch[rt][s[i]-'0'];
	}
}
void dfs(int rt,int dep){
	if(ch[rt][0])
		dfs(ch[rt][0],dep+1);
	else
		sg^=lowbit(l-dep);
	if(ch[rt][1])
		dfs(ch[rt][1],dep+1);
	else
		sg^=lowbit(l-dep);
}

int main(){
	cin>>n>>l;
	cnt=1;
	for(int i=1;i<=n;++i){
		cin>>s;
		insert();
	}
	dfs(1,0);
	puts(sg?"Alice":"Bob");
	return 0;
}