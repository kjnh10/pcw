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
int n,a[3][100005];
int main(){
	cin>>n;
	rep(i,3)rep(j,n){
		scanf("%d",&a[i][j]);
	}
	rep(i,3) sort(a[i],a[i]+n);
	ll ret = 0;
	rep(i,n){
		int x = a[1][i];
		int d = lower_bound(a[0],a[0]+n,x)-a[0];
		int e = upper_bound(a[2],a[2]+n,x)-a[2];
		ret += 1LL*d*(n-e);
	}
	cout<<ret<<endl;
}