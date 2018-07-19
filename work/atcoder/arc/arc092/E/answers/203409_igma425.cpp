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
using ll = long long;
int main(){
	int N;
	cin>>N;
	vector<ll> a(N);
	rep(i,N){
		cin>>a[i];
	}
	ll mx = -1e18;
	vector<int> ag;
	rep(t,2){
		vector<int> v;
		ll sm = 0;
		for(int i=t;i<N;i+=2){
			if(a[i]>=0){
				sm += a[i];
				v.pb(i);
			}
		}
		if(!v.empty() && mx<sm){
			mx = sm;
			ag = v;
		}
	}
	if(ag.empty()){
		int x = 0;
		rep(i,N) if(mx<a[i]){
			mx = a[i];
			x = i;
		}
		ag = {x};
	}
	cout<<mx<<endl;
	vector<int> op;
	int L = ag.front(), R = ag.back();
	rep(i,N-1-R) op.pb(N-1-i);
	rep(i,L) op.pb(0);
	for(int i=L+2;i<=R;i+=2){
		if(a[i]>=0) op.pb(1);
		else op.pb(2);
	}
	cout<<op.size()<<endl;
	for(int x: op) cout<<x+1<<endl;
}
