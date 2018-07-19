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
vector<int> xs,ys;
void add(int x,int y){
	xs.pb(x);
	ys.pb(y);
}
int main(){
	int N,a[50];
	cin>>N;
	rep(i,N) cin>>a[i];
	int mx = -1e9, mn = 1e9,amx=-1,amn=-1;
	rep(i,N){
		if(mx<a[i]) mx=a[i],amx=i;
		if(mn>a[i]) mn=a[i],amn=i;
	}
	if(mx > -mn){
		rep(i,N) add(amx,i);
		rep(i,N-1) add(i,i+1);
	}else{
		rep(i,N) add(amn,i);
		rep(i,N-1) add(N-1-i,N-2-i);
	}
	cout<<xs.size()<<endl;
	rep(i,xs.size()){
		cout<<xs[i]+1<<" "<<ys[i]+1<<endl;
	}
}
