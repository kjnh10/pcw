#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

ll readLL(){
	ll i;
	scanf("%lld",&i);
	return i;
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(a>b)
		a=b;
}

const int mod=1000000007;
template<class T,class U>
void add(T& a,U b){
	a=((ll)a+b)%mod;
}

template<>
void add(int& a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}

template<class T,class U>
void sub(T& a,U b){
	a=((ll)a-b%mod+mod)%mod;
}

template<>
void sub(int& a,int b){
	a-=b;
	if(a<0)a+=mod;
}

template<class T,class U>
void mult(T& a,U b){
	a=((ll)a*b)%mod;
}

ll modPow(ll a,ll p){
	ll s=1;
	REP(i,30){
		if((p>>i)&1)
			mult(s,a);
		mult(a,a);
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

struct UnionFind{
	vi group;
	vector<vi> member;
	void Init(int n){
		group.resize(n);
		REP(i,n)
			group[i]=i;
		member.assign(n,vi());
		REP(i,n)
			member[i].PB(i);
	}
	bool Same(int a,int b){
		return group[a]==group[b];
	}
	void Unite(int a,int b){
		a=group[a],b=group[b];
		if(a==b)
			return;
		if(member[a].size()<member[b].size())
			swap(a,b);
		for(auto v:member[b]){
			group[v]=a;
			member[a].PB(v);
		}
	}
} uf;

struct Edge{
	int from,to,idx;
};

int main(){
	vector<ll> fact({1});
	FOR(i,1,114154)
		fact.PB(fact.back()*i%mod);
	auto comb=[&](int a,int b){
		return fact[a]*modInv(fact[b])%mod*modInv(fact[a-b])%mod;
	};
	int n=read(),m=read(),k=read();
	vector<vector<Edge>> g(n);
	REP(i,m){
		int a=read()-1,b=read()-1;
		g[a].PB(Edge{a,b,i});
		g[b].PB(Edge{b,a,i});
	}
	vi dep(n,0);
	vector<Edge> parEdge(n);
	vector<bool> vis(n,false);
	function<void(int,Edge,int)> dfs;
	dfs=[&](int v,Edge pe,int d){
		if(vis[v])
			return;
		vis[v]=true;
		parEdge[v]=pe;
		dep[v]=d;
		for(auto e:g[v])
			dfs(e.to,e,d+1);
	};
	REP(i,n)
		dfs(i,Edge{-1,-1,-1},0);
	vi covs(m,0);
	REP(i,n)
		for(auto e:g[i])if(dep[i]+1<dep[e.to]){
			int x=e.to;
			while(x!=i){
				covs[parEdge[x].idx]++;
				x=parEdge[x].from;
			}
		}
	uf.Init(m);
	vi simpleCycle,compCycle;
	int freeEdge=m;
	REP(i,n)
		for(auto e:g[i])if(dep[i]+1<dep[e.to]){
			vector<Edge> tmp({e});
			bool p=false;
			int x=e.to;
			while(x!=i){
				tmp.PB(parEdge[x]);
				if(covs[parEdge[x].idx]>=2)
					p=true;
				x=parEdge[x].from;
			}
			if(!p){
				freeEdge-=tmp.size();
				simpleCycle.PB(tmp.size());
			}else{
				for(auto f:tmp)
					uf.Unite(tmp.front().idx,f.idx);
			}
		}
	REP(i,m)if(uf.group[i]==i&&(int)uf.member[i].size()>1){
		compCycle.PB(uf.member[i].size());
		freeEdge-=uf.member[i].size();
	}
	auto calc1=[&](int s){
		ll ret=0;
		FOR(t,1,s+1)
			add(ret,modPow(k,__gcd(s,t)));
		return ret*modInv(s)%mod;
	};
	auto calc2=[&](int s){
		return comb(s+k-1,s);
	};
	ll ans=1;
	for(auto v:simpleCycle)
		mult(ans,calc1(v));
	for(auto v:compCycle)
		mult(ans,calc2(v));
	mult(ans,modPow(k,freeEdge));
	cout<<ans<<endl;
}
