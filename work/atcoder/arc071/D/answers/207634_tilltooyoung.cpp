#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
#include <ext/hash_set>
struct Hasher
{int operator()(int x)const{return x^0x45678901;}};
typedef __gnu_cxx::hash_set<int,Hasher> hashset_int;
int n,m,x[SZ],y[SZ];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	for(int i=1;i<=m;i++) scanf("%d",y+i);
	ll ax=0,ay=0,t=0,s=0,MOD=1e9+7;
	for(int i=1;i<=n;i++)
	{
		ax+=t*x[i]-s; ax%=MOD;
		++t; s+=x[i]; s%=MOD;
	}
	t=s=0;
	for(int i=1;i<=m;i++)
	{
		ay+=t*y[i]-s; ay%=MOD;
		++t; s+=y[i]; s%=MOD;
	}
	ax*=ay; ax=(ax%MOD+MOD)%MOD;
	printf("%d\n",ax);
}
