#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<long double,long double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<61;
const double pi=acos(-1);
const double eps=1e-10;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

const int M=10;

int n;
vvi a,b;

int main(){
	cin>>n;
	a=vvi(n,vi(M));
	b=vvi(n,vi(M+1));
	for(int i=0;i<n;i++) for(int j=0;j<M;j++) cin>>a[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<=M;j++) cin>>b[i][j];
	ll res=-inf;
	for(int i=1;i<1<<M;i++){
		ll tmp=0;
		for(int j=0;j<n;j++){
			int cnt=0;
			for(int k=0;k<M;k++) if((i&1<<k)&&a[j][k]) cnt++;
			tmp+=b[j][cnt];
		}
		res=max(res,tmp);
	}
	cout<<res<<endl;
}