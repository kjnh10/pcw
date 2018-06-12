#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef complex<double> pt;
int dist[100005],n;
int main(){
	cin>>n;
	priority_queue<P,vector<P>,greater<P> >que;
	fill(dist,dist+100005,INF);
	for(int i=1;i<=9;i++){
		que.push(mp(i,i%n));
		dist[i%n] = min(dist[i%n],i);
	}
	while(!que.empty()){
		P p = que.top(); que.pop();
		if(p.fi != dist[p.sc]) continue;
		//cout<<p.fi<<" "<<p.sc<<endl;
		for(int i=0;i<=9;i++){
			int nxt = p.sc*10+i;
			int val = p.fi+i;
			nxt %= n;
			if(dist[nxt] > val){
				dist[nxt] = val;
				que.push(mp(val,nxt));
			}
		}
	}
	cout<<dist[0]<<endl;
}