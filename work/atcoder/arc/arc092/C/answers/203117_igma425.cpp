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
	vector<int> x2y(2*N);
	vector<bool> isb(2*N);
	rep(t,2){
		rep(i,N){
			int x,y;
			cin>>x>>y;
			x2y[x] = y;
			isb[x] = t;
		}
	}
	vector<bool> used(2*N);
	int ans = 0;
	rep(x,2*N){
		if(isb[x]){
			int y = x2y[x];
			int mxy = -1, agx = -1;
			rep(i,x) if(!isb[i] && !used[i]){
				if(mxy<x2y[i] && x2y[i]<y){
					mxy = x2y[i];
					agx = i;
				}
			}
			if(agx!=-1){
				ans++;
				used[agx] = 1;
			}
		}
	}
	cout<<ans<<endl;
}
