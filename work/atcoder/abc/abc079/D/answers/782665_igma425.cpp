#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int main(){
	int H,W;
	cin>>H>>W;
	int d[10][10];
	rep(i,10) rep(j,10){
		cin>>d[i][j];
	}
	rep(i,10) rep(j,10) rep(k,10) chmin(d[j][k],d[j][i]+d[i][k]);
	int cnt[10]={};
	int ans = 0;
	rep(i,H) rep(j,W){
		int x;
		cin>>x;
		if(x==-1) continue;
		ans += d[x][1];
	}
	cout<<ans<<endl;

}
