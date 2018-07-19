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
int n,q;
ll x[100005],L;
int go[100005][20];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	cin >> L >> q;
	for(int i=1;i<=n;i++){
		go[i][0] = upper_bound(x+1,x+n+1,x[i]+L)-x;
		go[i][0]--; 
	}
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			go[i][j] = go[go[i][j-1]][j-1];
		}
	}
	for(int i=0;i<q;i++){
		int a,b; scanf("%d%d",&a,&b); if(a>b) swap(a,b);
		int lb = 0,ub = 200000;
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			int cur = a;
			for(int j=0;j<20;j++){
				if(((mid>>j)&1)) cur = go[cur][j];
			}
			if(cur >= b) ub = mid;
			else lb = mid;
		}
		printf("%d\n",ub);
	}
}