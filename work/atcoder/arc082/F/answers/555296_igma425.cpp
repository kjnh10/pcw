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
typedef long long ll;
typedef pair<ll,ll> P;

ll T;
int K,Q;

int main(){
	cin>>T;
	cin>>K;
	set<P> events;
	rep(i,K){
		int t;
		cin>>t;
		events.insert(P(t,-1));	//reverse query
	}
	cin>>Q;
	rep(i,Q){
		ll t,f;
		cin>>t>>f;
		events.insert(P(t,f));
	}

	bool inc = 0;
	ll pt = 0;
	ll a = 0, b = T, c = 0;
	for(P e:events){
		ll t = e.fs;
		ll x = e.sc;

		if(inc){
			ll d = t-pt;
			c += d;
			if(b+c>T) b = T-c;
			if(a>b) a = b;
		}else{
			ll d = t-pt;
			c -= d;
			if(a+c<0) a = -c;
			if(a>b) b = a;
		}
		if(x==-1){	//reverse
			inc = !inc;
		}else{		//answer
			cout<<max(a,min(b,x))+c<<endl;
		}
		pt = t;
	}
}
