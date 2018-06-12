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
	int N;
	cin>>N;
	vector<int> a(N),b(N);
	rep(i,N) cin>>a[i];
	rep(i,N) cin>>b[i];
	int ans = 0;
	rep(t,29){
		int T = 1<<(t+1);
		vector<int> xs,ys;
		rep(i,N){
			xs.pb(a[i]%T);
			ys.pb(b[i]%T);
			ys.pb(b[i]%T+T);
		}
		sort(all(xs));
		sort(all(ys));
		bool odd = 0;
		for(int x: xs){
			int s = (T-x)%T;
			int num = N - (lower_bound(all(ys),s+T/2) - lower_bound(all(ys),s));
			if(num%2) odd = !odd;
		}
		if(odd) ans |= 1<<t;
	}
	cout<<ans<<endl;
}
