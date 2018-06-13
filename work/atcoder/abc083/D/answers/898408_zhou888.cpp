#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=1e5+10;
char s[maxn];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans1=n,ans2=n;
	REP(i,1,n){
		if(s[i]=='1') ans1=min(ans1,max(n-i,i-1));
		else if(s[i]=='0') ans2=min(ans2,max(n-i,i-1));
	}
	printf("%d\n",max(ans1,ans2));
//	int L=1,R=n;
//	while(L<=R){
//		int Mid=(L+R)>>1;
//		if(check(Mid)) L=Mid+1;
//		else R=Mid-1;
//	}
//	printf("%d\n",L-1);
	return 0;
}