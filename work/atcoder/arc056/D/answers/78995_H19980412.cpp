#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int par[200005],ran[200005];
void init(){ for(int i=0;i<200005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int n,m,v;
vector<int>vec[200005];
int main(){
	scanf("%d%d%d",&n,&m,&v);
	init();
	for(int i=0;i<m;i++){
		int a,b; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		vec[a].pb(b);
	}
	vector<int>ans;
	for(int i=n;i>=1;i--){
		for(int j=0;j<vec[i].size();j++){
			unite(vec[i][j],i);
		}
		if(same(i,v)) ans.pb(i);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}