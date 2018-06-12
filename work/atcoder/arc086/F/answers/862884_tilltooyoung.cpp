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
#define SZ 666666
int n,N=0;ll a[333];
ll k;
queue<vector<ll> > qs;
map<vector<ll>,int> vs;
Edgc
int dd[SZ]; bool inq[SZ];
vector<ll> fy[SZ];
void spfa()
{
	queue<int> q; q.push(1);
	for(int i=1;i<=N;++i) dd[i]=1e9;
	dd[1]=0; inq[1]=1;
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		for esb(x,e,b)
		{
			int&d=dd[b];
			if(d<=vc[e]+dd[x]) continue;
			d=vc[e]+dd[x];
			if(!inq[b]) q.push(b),inq[b]=1;
		}
		inq[x]=0;
	}
}
map<vector<ll>,map<ll,ll> > aa;
int main()
{
	cin>>n>>k;
	vector<ll> v;
	for(int i=0;i<n;++i) cin>>a[i], v.pb(a[i]);
	sort(v.begin(),v.end());
	qs.push(v); vs[v]=++N;
	while(!qs.empty())
	{
		auto p=qs.front(); qs.pop();
		auto r=p;
		if(r[0])
		{
		for(int i=0;i<n;++i) r[i]=(r[i]-1)/2;
		if(!vs.count(r))
			vs[r]=++N,qs.push(r);
		ad_de(vs[p],vs[r],2);
		}
		r=p;
		for(int i=0;i<n;++i) r[i]=r[i]/2;
		if(!vs.count(r))
			vs[r]=++N,qs.push(r);
		ad_de(vs[p],vs[r],1);
	}
	for(auto p:vs) fy[p.se]=p.fi;
	spfa();
	for(int i=1;i<=N;++i) if(dd[i]<=k)
	{
		auto s=fy[i]; ll p=s.front(),
		np=max(p-(k-dd[i]),0LL);
		for(auto&xx:s) xx-=p;
		++aa[s][np]; --aa[s][p+1];
	}
	ll ans=0;
	const ll MOD=1e9+7;
	for(auto& s:aa)
	{
		ll ls=0;
		for(auto r=s.se.begin();r!=s.se.end();++r)
		{
			//cout<<r->fi<<","<<r->se<<" ";
			ls+=r->se;
			if(ls) ans-=r->fi,ans%=MOD,ans+=(++r)->fi,--r,ans%=MOD;
		}
		//cout<<"\n";
	}
	ans=(ans%MOD+MOD)%MOD;
	printf("%lld\n",ans);
}
