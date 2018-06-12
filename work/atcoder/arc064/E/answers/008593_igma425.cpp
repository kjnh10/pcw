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
int N;
double inf=1e18;
double x[1002],y[1002],r[1002];
double d[1002];
bool used[1002];
double yosupot(double x,double y){return sqrt(x*x+y*y);}
int main(){
	cin>>x[0]>>y[0]>>x[1]>>y[1];
	cin>>N;
	rep(i,N){
		cin>>x[i+2]>>y[i+2]>>r[i+2];
	}
	N+=2;
	rep(i,N) d[i]=inf;
	d[0]=0;
	rep(i,N){
		int v=-1;
		rep(j,N) if(!used[j]&&(v==-1||d[v]>d[j])) v=j;
		used[v]=1;
		rep(u,N){
			double dist=max(0.0,yosupot(x[v]-x[u],y[v]-y[u])-r[v]-r[u]);
			chmin(d[u],d[v]+dist);
		}
	}
	printf("%.12f\n",d[1]);
}
