#include <bits/stdc++.h>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
string f[15];

bool forbid[15][15][15][15];

bool rec(int mask,vector<P>mch,bool ok){
	int yet = -1;
	for(int i=0;i<n;i++){
		if(!((mask>>i)&1)){
			yet = i; break;
		}
	}
	if(yet != -1){
		vector<int>zan;
		for(int i=yet+1;i<n;i++){
			if(!((mask>>i)&1)){
				zan.pb(i);
			}
		}
		{
			for(int i=0;i<zan.size();i++){
				int newmask = mask+(1<<yet)+(1<<zan[i]);
				mch.pb(mp(yet,zan[i]));
				if(rec(newmask,mch,ok)) return true;
				mch.pop_back();
			}
		}
		if(ok){
			int newmask = mask+(1<<yet);
			mch.pb(mp(yet,yet));
			if(rec(newmask,mch,false)) return true;
		}
		return false;
	}
	else{
		bool bad[15][15]={};
		for(int i=0;i<mch.size();i++){
			int a = mch[i].fi,b = mch[i].sc;
			for(int c=0;c<m;c++) for(int d=0;d<m;d++) bad[c][d] |= forbid[a][b][c][d];
		}
		bool okk[(1<<12)]={};
		okk[0] = true;
		for(int i=0;i<(1<<m);i++){
			if(okk[i] == false) continue;
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					if( ((i>>j)&1) || ((i>>k)&1) ) continue;
					if(bad[j][k]) continue;
					if(__builtin_popcount(i) != m-1 && j==k) continue;
					okk[i | (1<<j) | (1<<k)] = true;
				}
			}
		}
		return okk[(1<<m)-1];
	}
}
int main(){
	cin>>n>>m;
	rep(i,n){
		cin>>f[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int a=0;a<m;a++){
				for(int b=0;b<m;b++){
					if(f[i][a] == f[j][b] && f[i][b] == f[j][a]);
					else{
						forbid[i][j][a][b] = true;
					}
				}
			}
		}
	}
	bool flag = rec(0,vector<P>(),n%2);
	puts(flag?"YES":"NO");
}