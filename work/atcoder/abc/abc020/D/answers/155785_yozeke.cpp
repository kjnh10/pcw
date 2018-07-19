#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(a));i>=((int)(b));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

#define PMAX 31623
#define MOD 1000000007

vector<int> p, d;
vector<lli> g;
vector<pair<lli, lli>> pf;
vector<vector<lli>> dd;
lli n, k;

void p_init(void){
	p.push_back(2);
	for(int i = 3; i <= PMAX; i+=2){
		bool f = true;
		rep(j, p.size()) if(i%p[j] == 0){
			f = false;
			break;
		}
		if(f) p.push_back(i);
	}
}

void p_fact(void){
	int i = 0;
	while(i < p.size() && p[i] < k){
		lli tk = k; int c = 0;
		while(tk%p[i] == 0){
			c++;
			tk /= p[i];
		}
		if(c!=0) pf.push_back(pair<lli, lli>(p[i] , c));
		i++;
	}
	lli pp = 1;
	rep(j, pf.size()) rep(l, pf[j].sec) pp *= pf[j].fir;
	if(pp!=k) pf.push_back(pair<lli, lli>(k/pp , 1));
	sort(pf.begin(), pf.end());
}

void dev(lli i, lli a){
	if(i == pf.size()){
		d.push_back(a);
	}else{
		lli t = 1;
		rep(j, pf[i].sec + 1){
			dev(i+1, a*t);
			t *= pf[i].fir;
		}
	}
	return;
}

void ddd(void){
	dd.resize(d.size());
	rep(i, dd.size()) reg(j, i+1, dd.size()-1) if(d[j]%d[i] == 0) dd[i].push_back(j);
	return;
}

int main(void){
	scanf("%lld%lld", &n, &k);
	p_init();
	p_fact();
	dev(0, 1);
	sort(d.begin(), d.end());
	if(d.back() != k) d.push_back(k);	
	ddd();
	g.resize(d.size());
	irep(i, d.size()){
		lli j = n/d[i];
		g[i] = (j*(j+1)/2)%MOD;
		rep(l, dd[i].size()) g[i] = (g[i] + MOD - (g[dd[i][l]]*(d[dd[i][l]]/d[i]))%MOD)%MOD;
	}	
	lli ans = 0;
	rep(i, g.size()) ans = (ans+lli(g[i]))%MOD;
	ans = (ans*k)%MOD;
	
	cout << ans << endl;
	
	return 0;
}